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
int p[205][205],mod=1e9+7,inv[205],C[205][205];
V<int> v[205];
int ans=0;
bool ff=1;
int vis[205];
void get(int fr,int x,int fa){
	for(auto u:v[x])if(u!=fa){
		p[fr][u]=p[fr][x]+1;
		get(fr,u,x);
	}
}
void dfs(int x,int fa,int fi){
	if(x==fi)ff=0;
	for(auto u:v[x])if(u!=fa){
		dfs(u,x,fi);
	}
}
void add(int &x,int y){
	x=(x+y)%mod;
} 
void dfs2(int x,int fa,int col){
	vis[x]=col;
	for(auto u:v[x])if(u!=fa)dfs2(u,x,col);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	FOR(i,1,n){
		get(i,i,-1);
//		FOR(j,1,n)cout<<p[i][j]<<' ';
//		cout<<'\n';
	}
	inv[1]=1;
	FOR(i,2,n)inv[i]=mod-inv[mod%i]*(mod/i)%mod;
	C[0][0]=1;
	FOR(i,0,n){
		FOR(j,0,n){
			add(C[i+1][j],C[i][j]*inv[2]);
			add(C[i][j+1],C[i][j]*inv[2]);
		}
	}
	FOR(i,0,n){
		FOR(j,1,n){
			add(C[i][j],C[i][j-1]);
		}
	}
	rep(i,1,n){
		FOR(j,i+1,n){
				int toa,tob;
				for(auto u:v[j]){
					ff=1;
					dfs(u,j,i);
					if(!ff){
						toa=u;break;
					}
				}
				for(auto u:v[i]){
					ff=1;
					dfs(u,i,j);
					if(!ff){
						tob=u;break;
					}
				}
			FILL(vis,0);
			dfs2(j,toa,1);dfs2(i,tob,-1);
			FOR(k,1,n){
				if(vis[k]==1){
					add(ans,inv[n]); 
				}else if(vis[k]==0){
					int ta=p[k][j]-p[k][i],A=(p[i][j]+ta)/2,B=(p[i][j]-ta)/2;
//					cout<<A<<' '<<B<<'\n';
					add(ans,inv[n]*C[A-1][B-1]%mod*inv[2]);
				}
			}
//			cout<<ans<<'\n';
		}
	}
	cout<<ans%mod;
	RE 0;
}