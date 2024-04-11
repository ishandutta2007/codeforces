#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=20;
int n,k,a[(1<<maxn)+5],cnt[(1<<maxn)+5];
typedef pair<int,int> pii;
struct edge{
	int from,to,cap,flow,cost;
};
vector<edge> edges;
vector<int> g[(1<<maxn)+5];
void add_edge(int u,int v,int w,int f){
	g[u].push_back(edges.size());
	edges.push_back({u,v,w,0,f});
	g[v].push_back(edges.size());
	edges.push_back({v,u,0,0,-f});
}
vector<int> s;
ll d[(1<<maxn)+5];
int p[(1<<maxn)+5];
bool inq[(1<<maxn)+5];
const ll inf=9e18;
bool spfa(){
	for(int i:s) d[i]=inf;
	d[1<<n]=inf;
	queue<int> q;
	q.push((1<<n)+1);
	while(q.size()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i:g[u]){
			edge& e=edges[i];
			if(e.flow>=e.cap) continue;
			if(d[u]+e.cost<d[e.to]){
				d[e.to]=d[u]+e.cost;
				p[e.to]=i;
				if(!inq[e.to]){
					q.push(e.to);
					inq[e.to]=1;
				}
			}
		}
	}
	return d[1<<n]<inf;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	for(int i=0;i<(1<<n);i++) a[i]=readint();
	for(int i=1;i<(1<<n);i++) cnt[i]=cnt[i>>1]+(i&1);
	vector<pii> vec;
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++) if(i>>j&1) vec.push_back({i,i^(1<<j)});
	int m=min((n*2-1)*(k-1)+1,(int)vec.size());
	nth_element(vec.begin(),vec.begin()+m-1,vec.end(),[](pii x,pii y){
		return a[x.first]+a[x.second]>a[y.first]+a[y.second];
	});
	for(int i=0;i<m;i++){
		int u=vec[i].first,v=vec[i].second;
		if(cnt[u]%2==1) swap(u,v);
		add_edge(u,v,1,-a[u]-a[v]);
	}
	for(int i=0;i<(1<<n);i++) if(g[i].size()){
		s.push_back(i);
		if(cnt[i]%2==1) add_edge(i,1<<n,1,0);
		else add_edge((1<<n)+1,i,1,0);
	}
	ll ans=0;
	for(int i=0;i<k;i++){
		if(!spfa()) break;
		ans-=d[1<<n];
		int u=1<<n;
		while(u!=(1<<n)+1){
			edges[p[u]].flow++;
			edges[p[u]^1].flow--;
			u=edges[p[u]].from;
		}
	}
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}