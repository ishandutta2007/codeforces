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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int f[1000005],finv[1000005],inv[1000005],i2[1000005],mod=1e9+7;
int C(int x,int y){
	if(x<y||x<0||y<0)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	m=n-m;
	if(m==0){
		cout<<n*k%mod<<'\n';RE;
	}
	int ans=0;
	rep(i,m,n){
		ans=(ans+((n-i))*i2[i]%mod*C(i-1,m-1))%mod;
	}
	cout<<ans*k%mod<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	i2[0]=1;
	i2[1]=(mod+1)/2;
	f[0]=f[1]=finv[0]=finv[1]=inv[1]=1;
	FOR(i,2,1000000){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
		f[i]=f[i-1]*i%mod;
		i2[i]=i2[i-1]*i2[1]%mod;
	}
	cin>>T;
	while(T--)solve();
	RE 0;
}