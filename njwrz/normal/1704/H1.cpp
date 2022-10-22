#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
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
int mod;
namespace yg {

int fac[123], cnt, omg, omk;
void getfac(int x) {
	for(int i = 2; i <= sqrt(x); i++) 
		if(x % i == 0) {
			fac[++cnt] = i;
			while(x % i == 0) x /= i;
		}
}
int qpow(int x, int y, int pmod) {
	int res = 1;
	if(x == 0) return 0;
	for(; y; x = 1ll * x * x % pmod, y >>= 1) if(y & 1) res = 1ll * res * x % pmod;
	return res;
}
bool cheak(int x) {
	for(int i = 1; i <= cnt; i++) 
		if(qpow(x, (mod - 1) / fac[i], mod) == 1) return 0;
	return 1;
}
int find() {
	getfac(mod - 1);
	for(int i = 2; i < mod; i++) 
		if(cheak(i)) {
			return i;
		} 
	return -1;
}

}
int G;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
struct poly_op {
	int qpow(int a, int b, int p) {
		int res = 1;
		for (; b; b >>= 1, a = a * a % mod) {
			if (b & 1)
				res = res * a % mod;
		}
		return res;
	}
	int N;
	void bit_reverse(int N, int *r) {
		for (int i = 0, j = 0; i < N; i++) {
			if (i > j)
				swap(r[i], r[j]);
			for (int l = N >> 1; (j ^= l) < l; l >>= 1);
		}
	}
	int inv3;
	int pow3[(1 << 18) + 5], powinv3[(1 << 18) + 5];
	void pre(int num) {
		N = num;
		inv3 = qpow(G, mod - 2, mod);
		for (int i = 1; i <= N; i <<= 1)
			pow3[i] = qpow(G, (mod - 1) / i, mod);
		for (int i = 1; i <= N; i <<= 1)
			powinv3[i] = qpow(inv3, (mod - 1) / i, mod);
	}
	void NTT(int n, int *r, int f) {
		bit_reverse(n, r);
		for (int i = 2; i <= n; i <<= 1) {
			int m = i >> 1;
			for (int j = 0; j < n; j += i) {
				int w = 1, wn = pow3[i];
				if (f == -1)
					wn = powinv3[i];
				for (int k = 0; k < m; k++) {
					int z = r[j + m + k] * w % mod;
					r[j + m + k] = r[j + k] - z;
					if (r[j + m + k] < 0)
						r[j + m + k] += mod;
					add(r[j + k], z);
					w = w * wn % mod;
				}
			}
		}
		if (f == -1) {
			int inv = qpow(n, mod - 2, mod);
			for (int i = 0; i < n; i++)
				r[i] = r[i] * inv % mod;
		}
	}
} OP;
int ta[(1 << 18) + 5], tb[(1 << 18) + 5], N;

void DO() {
	OP.NTT(N, ta, 1);
	OP.NTT(N, tb, 1);
	rep(i, 0, N)ta[i] = ta[i] * tb[i] % mod;
	OP.NTT(N, ta, -1);
}

void operator +=(V<int> &x, V<int> y) {
	while(x.size()<y.size())x.PB(0);
	rep(i, 0, (int)(y.size()))add(x[i], y[i]);
}

V<int> operator *(V<int> x, V<int> y) {
	V<int> re(x.size() + y.size() - 1);
	N = 1;
	while (N < (int)re.size())
		N <<= 1;
	rep(i, 0, N)ta[i] = tb[i] = 0;
	rep(i, 0, (int)x.size())ta[i] = x[i];
	rep(j, 0, (int)y.size())tb[j] = y[j];
	OP.NTT(N, ta, 1);
	OP.NTT(N, tb, 1);
	rep(i, 0, N)ta[i] = ta[i] * tb[i] % mod;
	OP.NTT(N, ta, -1);
	rep(i, 0, (int)re.size())re[i] = ta[i];
	RE re;
}
int n;
int dp[3][100005];
int f[100005],inv[100005],finv[100005];
const int B=5e18;
void add2(int &x,int y){
	x+=y;
	if(x>B)x%=mod;
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
	FOR(i,2,n){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
int get(int x,int y){
	if(!x||!y)RE 1;
	RE C(x+y-1,y-1);
}
int dp2[2][100005],p[100005],dp3[100005],ans[100005];
void solve2(int l,int r){
	if(l==r){
		rep(i,0,2)dp2[i][l]%=mod;RE; 
	}
	int mid=(l+r)>>1;
	solve2(l,mid);
	V<int> v1(r-l+1),v2(mid-l+1);
	FOR(i,l,mid)v2[i-l]=dp2[1][i]*finv[i-1]%mod;
	FOR(i,1,r-l)v1[i]=dp[0][i]*finv[i]%mod;
	V<int> now=v1*v2;
	FOR(i,mid+1,r)add2(dp2[0][i],now[i-l]*f[i-1]);
	FOR(i,l,mid)v2[i-l]=(dp2[1][i]+dp2[0][i])*finv[i-1]%mod;
	FOR(i,1,r-l)v1[i]=(dp[0][i]+dp[1][i]+dp[2][i])*finv[i]%mod;
	now=v1*v2;
	FOR(i,mid+1,r)add2(dp2[1][i],now[i-l]*f[i-1]);
	solve2(mid+1,r);
}
void solve3(int l,int r){
	if(l==r){
		dp3[l]%=mod;RE; 
	}
	int mid=(l+r)>>1;
	solve3(l,mid);
	V<int> v1(r-l+1),v2(mid-l+1);
	FOR(i,l,mid)v2[i-l]=dp3[i]*finv[i-1]%mod;
	FOR(i,1,r-l)v1[i]=(dp[0][i]+dp[1][i])*finv[i]%mod;
	V<int> now=v1*v2;
	FOR(i,mid+1,r)add2(dp3[i],now[i-l]*f[i-1]);
	solve3(mid+1,r);
}
void solve4(int l,int r){
	if(l==r){
		ans[l]%=mod;RE; 
	}
	int mid=(l+r)>>1;
	solve4(l,mid);
	V<int> v1(r-l+1),v2(mid-l+1);
	FOR(i,l,mid)v2[i-l]=ans[i]*finv[i]%mod;
	FOR(i,2,r-l)v1[i]=p[i]*finv[i-1]%mod;
	V<int> now=v1*v2;
	FOR(i,mid+1,r)add2(ans[i],now[i-l]*f[i-1]);
	solve4(mid+1,r);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>mod;
//	n=5000;mod=998244353;
	G=yg::find();
	OP.pre(1<<18);
	pref();
	dp[0][1]=1;
	FOR(now,2,n){
		rep(i,1,now){
			int j=now-i;
			int val=j*get(i-1,j)%mod;
			add2(dp[2][i+j],(dp[0][i]+dp[1][i]+dp[2][i])*(dp[0][j]+dp[2][j])%mod*val);
			
			add2(dp[1][i+j],(dp[0][i]+dp[1][i])*dp[0][j]%mod*val);
			
			add2(dp[1][i+j],dp[1][i]*dp[2][j]%mod*val);
			
			add2(dp[0][i+j],dp[0][i]*dp[2][j]%mod*val);
		}
		rep(i,0,3)dp[i][now]%=mod;
	}
	FOR(j,1,n)rep(i,0,3)dp[i][j]=dp[i][j]*j%mod;
	rep(T,0,2){
		FILL(dp2,0);
		dp2[T][0]=1;
		int i=0;
		FOR(j,1,n){
			int val=get(j,i);
			add2(dp2[1][i+j],(dp2[0][i]+dp2[1][i])*(dp[1][j]+dp[0][j]+dp[2][j])%mod*val);
			add2(dp2[0][i+j],dp2[1][i]*dp[0][j]%mod*val);
		}
		solve2(1,n);
		FOR(i,2,n)add(p[i],dp2[T][i]);
	}
	FOR(i,2,n)add(p[i],mod-dp[2][i]);
	dp3[0]=1;
	int i=0;
	FOR(j,1,n-i){
		dp3[i]%=mod;
		int val=get(j,i);
		add2(dp3[i+j],dp3[i]*val%mod*(dp[0][j]+dp[1][j]));
	}
	solve3(1,n);
	dp3[n]%=mod;
	FOR(i,2,n)add(p[i],mod-dp3[i]);
	ans[0]=1;
	solve4(0,n);
	cout<<ans[n];
//	FOR(i,1,n)cout<<ans[i]<<'\n';
	RE 0;
}