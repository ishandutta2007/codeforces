/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int d[405][405],mod=998244353;
bool vis[405];
V<int> v[405];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,n){
			d[i][j]=(i==j)?0:1e9;
		}
	}
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		d[x][y]=1;
		d[y][x]=1;
		v[x].PB(y);
		v[y].PB(x);
	}
	FOR(i,1,n){
		FOR(j,1,n){
			FOR(k,1,n){
				gmin(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}
//	FOR(i,1,n){
//		FOR(j,1,n)cout<<d[i][j]<<' ';
//		cout<<'\n';
//	}
	FOR(S,1,n){
		FOR(T,1,n){
			FILL(vis,0);
			int now=S;
			vis[S]=1;
			while(now!=T){
				for(auto u:v[now]){
					if(d[S][u]==d[S][now]+1&&d[T][u]==d[T][now]-1){
						now=u;vis[now]=1;break;
					}
				}
			}
			int ans=1;
			FOR(i,1,n)if(!vis[i]){
				int t=0;
				for(auto u:v[i]){
					if(d[S][u]==d[S][i]-1&&d[T][u]==d[T][i]-1){
						t++;
					}
				} 
				ans=ans*t%mod;
			}
			cout<<ans<<' ';
		}
		cout<<'\n';
	}
	RE 0;
}