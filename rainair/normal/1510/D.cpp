#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXL = 3e5 + 5;
const int mod = 998244353;
const ldb eps = 1e-10;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

namespace Poly
{
	const int g = 3;
	const int N = 524288;
	
	int omega[N+5];
	inline void init(void)
	{
		omega[0] = 1; omega[1] = pw(g, (mod-1) / N);
		for(int i=2; i<N; ++i) omega[i] = (ll)omega[i-1] * omega[1] %mod;
	}
	inline void dft(int a[],int n)
	{
		for(int i=0,j=0; i<n; ++i)
		{
			if(i<j) swap(a[i],a[j]);
			for(int k=n>>1; (j^=k)<k; k>>=1);
		}
		for(int k=1, step=N>>1; k<n; k<<=1, step>>=1)
			for(int i=0; i<n; i+=k<<1)
				for(int j=i, cur=0; j<i+k; ++j, cur+=step)
				{
					int tmp = (ll)a[j+k] * omega[cur] %mod;
					add_mod(a[j+k] = a[j], mod - tmp); add_mod(a[j], tmp);
				}
	}
	inline void idft(int a[],int n){ dft(a,n); reverse(a+1,a+n);}
	
	int a[N+5], b[N+5];
	inline vector<int> mul(const vector<int> &A,const vector<int> &B)
	{
		if(!A.size() || !B.size()) return vector<int>();
		vector<int> res((int)A.size() + (int)B.size() - 1);
		int n = 1;
		while(n < (int)res.size()) n <<= 1;
		for(int i=0; i<n; ++i) a[i] = i<(int)A.size()? A[i]: 0;
		for(int i=0; i<n; ++i) b[i] = i<(int)B.size()? B[i]: 0;
		dft(a,n); dft(b,n);
		for(int i=0; i<n; ++i) a[i] = (ll)a[i] * b[i] %mod;
		idft(a,n);
		int invn = pw(n, mod-2);
		for(int i=0; i<(int)res.size(); ++i)
			res[i] = (ll)a[i] * invn %mod;
		return res;
	}
} using Poly::mul;

struct Data
{
	vector<int> a;
	inline int size(void) const { return a.size();}
	inline int operator [] (const int x) const { return a[x];}
	Data(void){}
	Data(int x){ while(x) a.push_back(x % 10), x /= 10;}
	inline void trim(void){ while(a.size() && !a.back()) a.pop_back();}
	inline bool operator < (const Data &b) const
	{
		if((int)a.size() != (int)b.size()) return (int)a.size() < (int)b.size();
		for(int i=(int)a.size()-1; i>=0; --i)
			if(a[i] != b[i]) return a[i] < b[i];
		return 0;
	}
	inline Data operator * (const Data &b)
	{
		Data res;
		res.a = mul(a, b.a);
		ll lst = 0;
		for(int i=0; i<(int)res.size(); ++i)
		{
			lst += res[i];
			res.a[i] = lst % 10; lst /= 10;
		}
		while(lst) res.a.push_back(lst % 10), lst /= 10;
		return res;
	}
};

inline Data mul(const vector<int> &a,int l,int r)
{
	if(l == r) return Data(a[l]);
	int mid = (l+r)>>1;
	return mul(a,l,mid) * mul(a,mid+1,r);
}

int a[MAXN];
ldb f[MAXN][12];
pii g[MAXN][12];

int main(void)
{
//	Poly::init();
	
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=0; i<=9; ++i) f[0][i] = -1;
	
	f[0][1] = 0;
	for(int i=1; i<=n; ++i)
	{
		ldb cur = logl(a[i]);
		for(int j=0; j<=9; ++j) f[i][j] = f[i-1][j], g[i][j] = make_pair(0, j);
		
		for(int j=0; j<=9; ++j) if(f[i-1][j] > -0.5)
		{
			int to = j * a[i] % 10;
			if(f[i][to] <= f[i-1][j] + cur + eps)
				f[i][to] = f[i-1][j] + cur,
				g[i][to] = make_pair(1, j);
		}
	}
	
	if(f[n][d] > -0.5)
	{
		vector<int> ans;
		int cur = d;
		for(int i=n; i>=1; --i)
		{
			if(g[i][cur].first) ans.push_back(a[i]);
			cur = g[i][cur].second;
		}
		if(ans.size())
		{
			printf("%d\n",(int)ans.size());
			for(int i=0; i<(int)ans.size(); ++i)
				printf("%d ",ans[i]);
			return 0;
		}
	}
	printf("-1");
	return 0;
}