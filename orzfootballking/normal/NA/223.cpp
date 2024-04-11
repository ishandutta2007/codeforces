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
int on[1000005],m=1e6,mod=1e9+7,l[1000005];
int POW(int x){
	if(!x)RE 1;
	int t=POW(x/2);
	if(x&1){
		RE t*t%mod*2%mod;
	}else RE t*t%mod;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n){
		int x;
		cin>>x;
		on[x]++;
	}
	int ans=0;
	for(int i=m;i>=2;i--){
		int now=0;
		for(int j=i;j<=m;j+=i){
			now+=on[j];
		}
		if(now){
			int cos=POW(now-1);
			l[i]=cos*now%mod;
			for(int j=i*2;j<=m;j+=i)l[i]=(l[i]-l[j]+mod)%mod;
			ans=(ans+l[i]*i)%mod;
		}
	}
	cout<<ans;
	RE 0;
}