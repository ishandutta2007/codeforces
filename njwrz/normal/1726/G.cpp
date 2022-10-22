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
using namespace std;
int cnt[400005][2];
int n;
const int mod=998244353;
int f[300005],inv[300005],finv[300005];
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
int a[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		int x;
		cin>>x;
		cnt[a[i]][x]++;
	}
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,n){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	int M=0;
	int mi=1e18;
	FOR(i,1,n+n)if(cnt[i][0]||cnt[i][1])gmin(mi,i);
	if(cnt[mi][0]+cnt[mi][1]==n){
		cout<<f[n];RE 0;
	}
	M=mi+n-1;
	FOR(i,M+1,n+n)if(cnt[i][0]||cnt[i][1]){
		cout<<0;RE 0;
	}
	FOR(i,1,M-1)if(cnt[i][1]>1){
		cout<<0;RE 0;
	}
	FOR(i,1,M-n)if(cnt[i][0]||cnt[i][1]){
		cout<<0;RE 0;
	}
	int sum=0,sum2=0,ans=C(n,cnt[M][1]);
	FOR(i,1,n+n){
		ans=ans*f[cnt[i][0]]%mod*f[cnt[i][1]]%mod;
	}
	FOR(i,M-n+1,M){
		if(cnt[i][0]){
			if(i+sum2<M){
				cout<<0;RE 0;
			}
		}
		if(cnt[i][1]){
			if(n-sum-sum2-cnt[i][0]-cnt[i][1]+i>M){
				cout<<0;RE 0;
			}
		}
		sum+=cnt[i][0];sum2+=cnt[i][1];
	}
	cout<<ans;
	RE 0;
}