#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define mod 1000000007
int f[400005],inv[400005],finv[400005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
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
int n,a[200005]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,400004){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	cin>>n;n++;
	FOR(i,1,n)cin>>a[i];
	while(a[n]==0)n--;
	int ans=0;
	FOR(i,1,n){
		add(ans,C(i-1+a[i],i));
	}
	cout<<ans;
	RE 0;
}