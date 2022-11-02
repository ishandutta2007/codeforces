#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
using namespace std;
int n;
bool f[500005],in[500005];
int ans[500005];
V<int> v[500005][2],q[500005],p,fr[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	int x,y,z;
	FOR(i,1,m){
		cin>>x>>y>>z;
		v[x][z].PB(y);
		q[y].PB(x);
	} 
	FOR(i,1,n)rep(j,0,2)sort(ALL(v[i][j]));
	p.PB(n);f[n]=1;in[n]=1;
	int cnt=0;
	while(!p.empty()){
		V<int> t,nxt;
		for(auto u:p){
			if(u==1){
				cout<<cnt<<'\n';
				FOR(i,1,n){
					if(f[i]){
						cout<<ans[i];
					}else cout<<0;
				}
				RE 0;
			}
		}
		cnt++;
		for(auto u:p)for(auto l:q[u])fr[l].clear();
		for(auto u:p){
			for(auto l:q[u]){
				if(!in[l]){
					t.PB(l);fr[l].PB(u);
				}
			}
		}
		sort(ALL(t));
		t.erase(unique(ALL(t)),t.end());
		for(auto u:t){
			bool to[2]={};
			rep(now,0,2){
				for(auto g:fr[u]){
					if(lwb(ALL(v[u][now]),g)!=v[u][now].end()&&(*lwb(ALL(v[u][now]),g))==g){
						to[now]=1;break;
					}
				}
			}
			if(f[u]==1){
				if(to[ans[u]]){
					nxt.PB(u);in[u]=1;
				}
				continue;
			}
			if(to[0]&&to[1]){
				ans[u]=0;nxt.PB(u);f[u]=1;in[u]=1;
			}else if(to[0]){
				ans[u]=1;f[u]=1;
			}else ans[u]=0,f[u]=1;
		}
		p=nxt;
	}
	cout<<-1<<'\n';
	FOR(i,1,n){
		if(f[i])cout<<ans[i];
		else cout<<0;
	}
	RE 0;
}