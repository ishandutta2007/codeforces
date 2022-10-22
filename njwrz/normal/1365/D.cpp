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
char c[55][55];
int n,m;
int fx[4][2]={
0,-1,
0,1,
1,0,
-1,0
};
bool f[55][55];
void dfs(int x,int y){
	f[x][y]=1;
	rep(i,0,4){
		int tx=x+fx[i][0],ty=y+fx[i][1];
		if(tx<1||tx>n|ty<1||ty>m)continue;
		if(c[tx][ty]!='#'){
			if(!f[tx][ty])dfs(tx,ty);
		}
	}
}
void solve(){
	cin>>n>>m;
	FOR(i,1,n)FOR(j,1,m)cin>>c[i][j];
	FOR(i,1,n){
		FOR(j,1,m){
			if(c[i][j]=='B'){
				rep(k,0,4){
					int tx=i+fx[k][0],ty=j+fx[k][1];
					if(tx<1||tx>n||ty<1||ty>m)continue;
					if(c[tx][ty]=='G'){
						cout<<"No\n";RE ;
					}else if(c[tx][ty]!='B'){
						c[tx][ty]='#';
					}
				}
			}
		}
	}
	FILL(f,0);
	if(c[n][m]!='#')dfs(n,m);
	FOR(i,1,n){
		FOR(j,1,m){
			if(c[i][j]=='G'&&!f[i][j]){
				cout<<"No\n";RE;
			}
		}
	}
	cout<<"Yes\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}