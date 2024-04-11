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
int f[500005],inv[500005],finv[500005],mod=998244353;
void init(){
	inv[1]=1;
	finv[0]=finv[1]=1;
	f[0]=f[1]=1;
	FOR(i,2,500000){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod; 
	}
} 
int C(int x,int y){
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>k>>n;init();
	int ans=0;
	FOR(i,1,k){
		int t=k/i;
		if(t<n)break;
		ans=(ans+C(t-1,n-1))%mod;
	}
	cout<<ans;
	RE 0;
}