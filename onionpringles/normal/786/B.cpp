#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 100000;
const int B = 1<<17;
#define mp make_pair
typedef pair<int,int> pii;
vector<pii> adj[N];
vector<pair<pii,int> > adj2[N];
vector<pair<int,pii> >tr[B<<1];
int chk[N];
long long dist[N];
set<int> S;
int main(){
	int n,m;scanf("%d%d",&n,&m);int s;scanf("%d",&s);s--;
	for(int i=0;i<m;i++){
		int tp;scanf("%d",&tp);
		if(tp==1){
			int u,v,c;scanf("%d%d%d",&u,&v,&c);u--;v--;
			adj[u].emplace_back(v,c);
		}
		else{
			int u,l,r,c;scanf("%d%d%d%d",&u,&l,&r,&c);u--;
			if(tp==2) adj2[u].emplace_back(pii(l-1,r-1),c);
			else{
				l-=2;
				for(l+=B,r+=B;l/2!=r/2;l/=2,r/=2){
					if(!(l&1))tr[l+1].emplace_back(i,mp(u,c));
					if(r&1)tr[r-1].emplace_back(i,mp(u,c));
				}
			}
		}
	}
	priority_queue<pair<long long,pii> > pq;
	for(int i=0;i<n;i++)dist[i]=9012345678912345678LL;
	for(int i=0;i<n;i++)S.insert(i);
	dist[s]=0;pq.push(mp(0,mp(s,s)));
	while(!pq.empty()){
		auto p = pq.top(); pq.pop();
		for(auto it=S.lower_bound(p.second.first);it!=S.end()&&*it<=p.second.second;it=S.erase(it)){
			int u = *it;
			dist[u]=-p.first;
			for(auto &x:adj[u]){
				int v=x.first;
				if(dist[v]>dist[u]+x.second){
					dist[v]=dist[u]+x.second;
					pq.push(mp(-dist[v],mp(v,v)));
				}
			}
			for(auto &x:adj2[u]){
				int L = x.first.first;
				int R = x.first.second;
				pq.push(mp(-dist[u]-x.second,mp(L,R)));
			}
			for(int i=B+u;i;i/=2){
				for(auto &x:tr[i]){
					int v=x.second.first;
					int j=x.first;
					if(chk[j])continue;
					chk[j]=1;
					if(dist[v]>dist[u]+x.second.second){
						dist[v]=dist[u]+x.second.second;
						pq.push(mp(-dist[v],mp(v,v)));
					}
				}
				tr[i].clear();
			}
		}
	}
	for(int i=0;i<n;i++){
		if(dist[i]==9012345678912345678LL)printf("-1 ");
		else printf("%lld ",dist[i]);
	}
	puts("");
}