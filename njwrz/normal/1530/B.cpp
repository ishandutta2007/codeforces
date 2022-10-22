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
int p[25][25];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int lst=0;
		FILL(p,0);
		p[1][1]=1;
		for(int i=3;i<=m;i+=2)p[1][i]=1;
		for(int i=3;i<=n;i+=2)p[i][1]=1;
		for(int i=3;i<=n;i+=2)p[i][m]=1;
		for(int i=3;i<=m;i+=2)p[n][i]=1;
		if(p[n-1][m]&&p[n][m-1])p[n][m-1]=0;
		if(p[n][m]&&(p[n-1][m]||p[n][m-1]))p[n][m]=0;
		FOR(i,1,n){
			FOR(j,1,m)cout<<p[i][j];
			cout<<'\n';
		}
		cout<<'\n';
	}
	RE 0;
}