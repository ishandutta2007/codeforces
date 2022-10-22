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
int n,a[1000005];
int val[1000005],mod=998244353,inv[1000005],cnt[1000005],f[1000005],finv[1000005]; 
int val2[1000005];
int C(int x,int y){
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
void solve(int x){
	if(x==n){
		val[x]=0;RE;
	}
	val[x]=0;
	FOR(i,1,n)if(cnt[i]){
		cnt[i]/=x;
		(val[x]+=cnt[i]*inv[n/x-1]%mod*(n/x-cnt[i]))%=mod;
		cnt[i]*=x;
	}
	val[x]=val[x]*x%mod;
	int sum=0;
	val2[x]=1;
	FOR(i,1,n)if(cnt[i]){
		cnt[i]/=x;
		sum+=cnt[i];
		val2[x]=val2[x]*C(sum,cnt[i])%mod;
		cnt[i]*=x;
	}
	val[x]=val[x]*val2[x]%mod;
}
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		y/=2;
		x=x*x%mod;
	}
	RE re;
}
void solve(){
	cin>>n;
	FOR(i,1,n)cnt[i]=val[i]=val2[i]=0;
	FOR(i,1,n)cin>>a[i],cnt[a[i]]++;
	int t=0;
	FOR(i,1,n)t=__gcd(t,cnt[i]);
	if(t==n){
		cout<<1<<'\n';RE ;
	}
	for(int i=1;i*i<=t;i++)if(t%i==0){
		solve(i);
		if(i*i!=t){
			solve(t/i);
		}
	}
	int ans=0,mul=0;
	for(int i=t;i>=1;i--){
		for(int j=i+i;j<=t;j+=i){
			val[i]=(val[i]-val[j]+mod)%mod;
			val2[i]=(val2[i]-val2[j]+mod)%mod;
		}
		ans=(ans+val[i]*inv[n/i])%mod;
		mul=(mul+val2[i]*inv[n/i])%mod;
	}
	cout<<ans*POW(mul,mod-2)%mod<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	inv[1]=1;finv[0]=finv[1]=f[0]=f[1]=1;
	FOR(i,2,1000000){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		f[i]=f[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	while(T--)solve();
	RE 0;
}