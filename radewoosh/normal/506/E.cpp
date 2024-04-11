//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
const int nax=207;
const ll mod=10007;

void add_self(int & a, int b) { a += b; if(a >= mod) a -= mod; }
void sub_self(int & a, int b) { a -= b; if(a < 0) a += mod; }
int mul(int a, int b) { return (ll) a * b % mod; }
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) r = mul(r, a);
		a = mul(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) { return my_pow(a, mod - 2); }
struct Massey {
	vector<int> start, coef; // 3 optional lines
	vector<vector<int>> powers;
	int memo_inv;
	// Start here and write the next ~25 lines until "STOP"
	int L; // L == coef.size() <= start.size()
	Massey(vector<int> in) { // O(N^2)
		L = 0;
		const int N = in.size();
		vector<int> C{1}, B{1};
		for(int n = 0; n < N; ++n) {
			assert(0 <= in[n] && in[n] < mod); // invalid input
			B.insert(B.begin(), 0);
			int d = 0;
			for(int i = 0; i <= L; ++i)
				add_self(d, mul(C[i], in[n-i]));
			if(d == 0) continue;
			vector<int> T = C;
			C.resize(max(B.size(), C.size()));
			for(int i = 0; i < (int) B.size(); ++i)
				sub_self(C[i], mul(d, B[i]));
			if(2 * L <= n) {
				L = n + 1 - L;
				B = T;
				d = my_inv(d);
				for(int & x : B) x = mul(x, d);
			}
		}
		cerr << "L = " << L << "\n";
		assert(2 * L <= N - 2); // NO RELATION FOUND :(
		// === STOP ===
		for(int i = 1; i < (int) C.size(); ++i)
			coef.push_back((mod - C[i]) % mod);
		assert((int) coef.size() == L);
		for(int i = 0; i < L; ++i)
			start.push_back(in[i]);
		while(!coef.empty() && !coef.back()) { coef.pop_back(); --L; }
		if(!coef.empty()) memo_inv = my_inv(coef.back());
		powers.push_back(coef);
	}
	vector<int> mul_cut(vector<int> a, vector<int> b) {
		vector<int> r(2 * L - 1);
		for(int i = 0; i < L; ++i)
			for(int j = 0; j < L; ++j)
				add_self(r[i+j], mul(a[i], b[j]));
		while((int) r.size() > L) {
			int value = mul(r.back(), memo_inv); // div(r.back(), coef.back());
			const int X = r.size();
			add_self(r[X-L-1], value);
			for(int i = 0; i < L; ++i)
				sub_self(r[X-L+i], mul(value, coef[i]));
			assert(r.back() == 0);
			r.pop_back();
		}
		return r;
	}
	int get(ll k) { // O(L^2 * log(k))
		if(k < (int) start.size()) return start[k];
		if(L == 0) return 0;
		k -= start.size();
		vector<int> vec = coef;
		for(int i = 0; (1LL << i) <= k; ++i) {
			if(i == (int) powers.size())
				powers.push_back(mul_cut(powers.back(), powers.back()));
			if(k & (1LL << i))
				vec = mul_cut(vec, powers[i]);
		}
		int total = 0;
		for(int i = 0; i < L; ++i)
			add_self(total, mul(vec[i], start[(int)start.size()-1-i]));
		return total;
	}
};

const int d=1507;
using vi=vector<int>;

int n;
char wcz[nax];

int kt;

int dp[nax][nax][d];

void dod(int &a, int b)
{
	a=(a+b)%mod;
}

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	scanf("%d", &kt);
	for (int i=0; i<=n+1; i++)
	{
		for (int j=0; j<=n+1; j++)
		{
			dp[i][j][0]=1;
			for (int l=1; l<d; l++)
				dod(dp[i][j][l], dp[i][j][max(0, l-2)]*26);
		}
	}
	for (int j=1; j<=n; j++)
	{
		for (int i=j; i>=1; i--)
		{
			for (int l=0; l<d; l++)
			{
				dp[i][j][l]=0;
				if (i==j)
				{
					if (!l)
						dod(dp[i][j][l], 1);
					if (l>=1)
						dod(dp[i][j][l], dp[i+1][j-1][l-1]);
					if (l>=2)
						dod(dp[i][j][l], dp[i][j][l-2]*25);
					continue;
				}
				if (wcz[i]==wcz[j])
				{
					dod(dp[i][j][l], dp[i+1][j-1][l]);
					if (l>=2)
						dod(dp[i][j][l], dp[i][j][l-2]*25);
				}
				else
				{
					if (l>=1)
					{
						dod(dp[i][j][l], dp[i+1][j][l-1]);
						dod(dp[i][j][l], dp[i][j-1][l-1]);
					}
					if (l>=2)
						dod(dp[i][j][l], dp[i][j][l-2]*24);
				}
			}
		}
	}
	vi wyn;
	for (int i=0; i<d; i++)
		wyn.push_back(dp[1][n][i]);
	printf("%d\n", Massey(wyn).get(kt));
	return 0;
}