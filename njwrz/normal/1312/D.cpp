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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int finv[200005],inv[200005],f[200005],mod=998244353;
int C(int x,int y){
	RE f[x]*finv[x-y]%mod*finv[y]%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,200000){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	int t=C(m,n-1);
	rep(i,1,n-2)t=t*2%mod;
	t=t*(n-2)%mod;
	cout<<t;
	RE 0;
}