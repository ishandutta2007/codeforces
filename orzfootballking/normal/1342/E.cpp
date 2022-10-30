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
int n,mod=998244353;
int POW(int x,int y){
	if(!y)RE 1;
	int t=POW(x,y/2);
	t=t*t%mod;
	if(y&1){
		RE t*x%mod;
	}else RE t;
}
int f[200005];
int C(int x,int y){
	RE f[x]*POW(f[y],mod-2)%mod*POW(f[x-y],mod-2)%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	f[0]=1;
	FOR(i,1,n)f[i]=f[i-1]*i%mod;
	if(n<=m){
		cout<<"0\n";RE 0;
	}
	m=n-m;
	int ans=0;
	rep(i,0,m){
		if(i&1){
			ans=(ans-C(m,i)*POW(m-i,n))%mod;
			ans=(ans+mod)%mod;
		}else{
			ans=(ans+C(m,i)*POW(m-i,n))%mod;
		}
	}
	ans=ans*C(n,m)%mod*(1+(n!=m))%mod;
	cout<<ans<<'\n';
	RE 0;
}