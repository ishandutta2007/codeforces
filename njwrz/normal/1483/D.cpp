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
int a[605][605],p[605][605];
int d[605][605];
bool vis[605][605];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q,m;
	cin>>n>>m;
	int x,y,z;
	FOR(i,1,n){
		FOR(j,1,n){
			if(i!=j)d[i][j]=1e18;
		}
	}
	FOR(i,1,m){
		cin>>x>>y>>z;
		d[x][y]=z;
		d[y][x]=z;
		p[x][y]=z;
		p[y][x]=z;
		vis[x][y]=vis[y][x]=1;
	}
	cin>>q;
	FOR(i,1,q){
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	FOR(k,1,n){
		FOR(i,1,n){
			FOR(j,1,n){
				gmin(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	FOR(k,1,n){
		FOR(i,1,n){
			FOR(j,1,n){
				gmax(a[i][k],a[i][j]-d[j][k]);
				gmax(a[i][j],a[i][k]-d[j][k]);
				gmax(a[k][j],a[i][j]-d[i][k]);
			}
		}
	}
	int ans=0;
	FOR(i,1,n){
		FOR(j,i+1,n){
			if(vis[i][j]){
				if(a[i][j]>=p[i][j])ans++;
			}
		}
	}
	cout<<ans;
	RE 0;
}