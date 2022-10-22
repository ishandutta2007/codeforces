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
int f[200005],finv[200005],inv[200005],mod=1e9+7;
int C(int x,int y){
	if(y>x||x<0||y<0)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
void solve(){
	int n;
	cin>>n;
	int l,r;
	cin>>l>>r;
	int t1=1-l,t2=r-n;
	int mid=n/2;
	int ans=C(n,mid)*min(t1,t2)%mod*(1+(mid*2!=n))%mod;
	FOR(i,min(t1,t2)+1,min(t1,t2)+n){
		int cntr=n-(l+i)+1,cntl=r-i;
		gmin(cntr,n);
		gmin(cntl,n);
		if(n-cntr<=mid&&n-cntl<=(n-mid)){
			ans=(ans+C(cntr+cntl-n,mid-(n-cntr)))%mod;
		}
		if(mid*2==n)continue;
		mid++;
		if(n-cntr<=mid&&n-cntl<=(n-mid)){
			ans=(ans+C(cntr+cntl-n,mid-(n-cntr)))%mod;
		}
		mid--;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	inv[1]=finv[0]=finv[1]=f[0]=f[1]=1;
	FOR(i,2,200000){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
		f[i]=f[i-1]*i%mod;
	}
	while(t--)solve();
	RE 0;
}