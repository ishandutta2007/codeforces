#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int p[1005][15],mod=1e9+7;
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int x,y;
	cin>>x>>y;
	int ans=0;
	p[1][0]=1;
	FOR(i,1,y){
		FOR(j,1,x){
			p[j][i]=(p[j-1][i]+p[j][i-1])%mod;
		}
	}
	FOR(i,1,x){
		FOR(j,i,x){
			ans=ans+p[i][y]*p[x-j+1][y];ans=ans%mod;
		}
	}
	cout<<ans;
	return 0;
}