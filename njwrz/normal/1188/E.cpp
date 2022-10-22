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
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
const int mod=998244353; 
int f[2000005],inv[2000005],finv[2000005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
void pref(){
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,2000002){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
int n,a[100005],p[1000005];
signed main(){
	pref();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int cnt=0;
	int mx=0;
	FOR(i,1,n)cin>>a[i],cnt+=a[i]==0,gmax(mx,a[i]);
	if(cnt>1){
		cout<<1;RE 0;
	}
	FOR(i,1,n)p[a[i]+1]++;
	FOR(i,n,mx)p[i]+=p[i-n];
	FOR(i,1,mx)p[i]+=p[i-1];
	int ans=0;
	FOR(i,0,mx){
		if(i<p[i])break;
		add(ans,C(i+n-1-p[i],n-1));
		if(i>=n)add(ans,mod-C(i-1-p[i-n],n-1));
	}
	cout<<ans;
	RE 0;
}