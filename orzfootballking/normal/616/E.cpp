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
int mod=1e9+7;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int ans=n%mod*(m%mod)%mod;
	int t=sqrt(n),lst=0;
	FOR(i,1,min(n,m)){
		if(n/i<=t)break;
		ans=(ans-(n-n%i)%mod+mod)%mod;
		lst=i;
	}
	if(lst==m){
		cout<<ans;RE 0;
	}
	for(int i=t;i>=1;i--){
		int r=n/i,l=n/(i+1)+1;
		if(r>=m)r=m;
		ans=(ans-(r+l)%mod*
		((r-l+1)%mod)%mod*(mod/2+1)%mod*i%mod+mod)%mod;
		if(r==m)break;
//		cout<<l<<' '<<r<<'\n';
	}
	cout<<ans;
	RE 0;
}