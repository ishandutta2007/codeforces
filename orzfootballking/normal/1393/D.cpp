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
int a1[2005][2005],a2[2005][2005],a3[2005][2005],a4[2005][2005];
char c[2005][2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c[i][j];
		}
	}
	FOR(i,1,n){
		FOR(j,1,m){
			if(c[i-1][j]!=c[i][j]||c[i][j-1]!=c[i][j]){
				a1[i][j]=1;continue;
			}
			a1[i][j]=min(a1[i-1][j],a1[i][j-1])+1;
		}
	}
	FOR(i,1,n){
		for(int j=m;j>=1;j--){
			if(c[i-1][j]!=c[i][j]||c[i][j+1]!=c[i][j]){
				a2[i][j]=1;continue;
			}
			a2[i][j]=min(a2[i-1][j],a2[i][j+1])+1;
		}
	}
	for(int i=n;i>=1;i--){
		FOR(j,1,m){
			if(c[i+1][j]!=c[i][j]||c[i][j-1]!=c[i][j]){
				a3[i][j]=1;continue;
			}
			a3[i][j]=min(a3[i+1][j],a3[i][j-1])+1;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(c[i+1][j]!=c[i][j]||c[i][j+1]!=c[i][j]){
				a4[i][j]=1;continue;
			}
			a4[i][j]=min(a4[i+1][j],a4[i][j+1])+1;
		}
	}
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,m){
			ans+=min(min(a1[i][j],a2[i][j]),min(a3[i][j],a4[i][j]));
		}
	}
	cout<<ans;
	RE 0;
}