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
const int mod=998244353;
void add(int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

struct poly_op {
	typedef complex<double> E;
	const double pi = acos(-1);
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
	int pow3[(1 << 19) + 5], powinv3[(1 << 19) + 5];
	void pre(int num) {
		N = num;
		inv3 = qpow(3, mod - 2, mod);
		for (int i = 1; i <= N; i <<= 1)
			pow3[i] = qpow(3, (mod - 1) / i, mod);
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
int ta[(1 << 19) + 5], tb[(1 << 19) + 5], N;

void DO() {
	OP.NTT(N, ta, 1);
	OP.NTT(N, tb, 1);
	rep(i, 0, N)ta[i] = ta[i] * tb[i] % mod;
	OP.NTT(N, ta, -1);
}
int p[27];
int s[200005],t[200005],n,m;
int val[200005];
int sum[200005];
int it[27];
signed main(){
	OP.pre(1<<19);
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,1,26)it[i]=i;
	srand(time(0));
	random_shuffle(it+1,it+26+1);
	FOR(i,1,26){
		int x;cin>>x;
		p[it[i]]=it[x];
	}
	string ts,tt;
	cin>>ts>>tt;
	n=ts.size();m=tt.size();
	FOR(i,1,n)s[i]=it[ts[i-1]-'a'+1];
	FOR(i,1,m)t[i]=it[tt[i-1]-'a'+1];
	FOR(i,1,m)sum[i]=sum[i-1]+t[i]*t[i]*t[i]*t[i];
	int su=0;
	FOR(i,1,n)su+=s[i]*s[i]*p[s[i]]*p[s[i]];
	N=1;
	while(N<n+m+1)N<<=1;
	FILL(ta,0);
	FILL(tb,0);
	FOR(i,1,m)ta[i]=t[i]*t[i];
	FOR(i,1,n)tb[i]=(s[n-i+1]*s[n-i+1]+p[s[n-i+1]]*p[s[n-i+1]]+4*s[n-i+1]*p[s[n-i+1]]+mod)%mod;
	DO();
	FOR(i,n+1,m+1)add(val[i-n],ta[i]);
	
	FILL(ta,0);
	FILL(tb,0);
	FOR(i,1,m)ta[i]=t[i]*t[i]*t[i];
	FOR(i,1,n)tb[i]=(p[s[n-i+1]]*2+2*s[n-i+1])%mod;
	DO();
	FOR(i,n+1,m+1)add(val[i-n],mod-ta[i]);
	
	FILL(ta,0);
	FILL(tb,0);
	FOR(i,1,m)ta[i]=t[i];
	FOR(i,1,n)tb[i]=(2*s[n-i+1]*p[s[n-i+1]]*p[s[n-i+1]]+s[n-i+1]*s[n-i+1]*p[s[n-i+1]]*2)%mod;
	DO();
	FOR(i,n+1,m+1)add(val[i-n],mod-ta[i]);
	FOR(i,1,m-n+1){
		val[i]+=sum[i+n-1]-sum[i-1];
		val[i]+=su;
		val[i]=(val[i]%mod+mod)%mod;
		if(val[i])cout<<0;else cout<<1;
	}
	RE 0;
}