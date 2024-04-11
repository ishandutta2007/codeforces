#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
using namespace __gnu_pbds;
int n,m;
int a[200005],b[200005];
int t[200005];
P<int,int> p[200005];
V<P<int,int> > v[200005];
int pos[200005],len,vis[200005];
void solve(){
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i],v[i].clear();
	FOR(i,1,n)cin>>b[i],t[i]=a[i]-b[i],a[i]-=b[i],a[i]+=a[i-1];
	FOR(i,1,m){
		vis[i]=0;
		int l,r;
		cin>>l>>r;
		v[l].PB(MP(r,i));
		v[r].PB(MP(l,i));
		p[i]=MP(l,r);
	}
	queue<int> q;
	set<int> s;
	FOR(i,1,n)s.emplace(i);
	FOR(i,1,m){
		if(a[p[i].F-1]==a[p[i].S]&&a[p[i].S]==0)q.emplace(i),vis[i]=1;
	}
	while(!q.empty()){
		int now=q.front();q.pop();
		int l=p[now].F,r=p[now].S;
		len=0;
		while(1){
			auto it=s.lower_bound(l);
//			cout<<"!"<<*it<<'\n';
			if(it==s.end()||(*it)>r)break;
			pos[++len]=*it;s.erase(it);
		}
		FOR(i,1,len){
			for(auto u:v[pos[i]]){
				int nowl=u.F,nowr=l;
				if(nowl>nowr)swap(nowl,nowr);
					auto tl=s.lower_bound(nowl);
					auto tr=s.upper_bound(nowr);
					if(tl!=s.end()&&tr!=s.begin()){
						tr--;
						if((*tl)<=(*tr)&&a[(*tl)-1]!=a[*tr]){
							continue;
						}
					}
					if(!vis[u.S]){
						q.emplace(u.S);vis[u.S]=1;
					}
			}
		}
	}
	for(auto u:s){
		if(t[u]){
			cout<<"NO\n";RE;
		}
	}
	cout<<"YES\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}