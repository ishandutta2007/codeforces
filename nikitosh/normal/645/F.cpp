#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX = 1e6 + 2, MAXN = MAX + 10, MOD = 1e9 + 7;

int fact[MAXN], obr[MAXN], obr_ch[MAXN], sum[MAXN], cur[MAXN], cnt[MAXN];
vi divisors[MAXN];

int power(int a, int n)
{
 	if (n == 0)
 		return 1;
 	if (n % 2 == 0)
 	{
 	 	int s = power(a, n / 2);
 	 	return (s * 1ll * s) % MOD;
 	}
 	return (power(a, n - 1) * 1ll * a) % MOD;
}

inline int c(int n, int k)
{
 	if (n < k)
 		return 0;
 	return ((fact[n] * 1ll * obr[k]) % MOD * 1ll * obr[n - k]) % MOD;
}

inline void add(LL &x, int k)
{
	x += k;
	if (x >= MOD)
		x -= MOD;
}

inline void sub(LL &x, int k)
{
	x -= k;
	if (x < 0)
		x += MOD;
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	fact[0] = 1;
	obr[0] = 1;
	obr_ch[0] = 1;
	forn (i, MAX)
	{
		fact[i + 1] = (fact[i] * 1ll * (i + 1)) % MOD;
		obr[i + 1] = power(fact[i + 1], MOD - 2);
		obr_ch[i + 1] = power(i + 1, MOD - 2);
	}
	forab (i, 1, MAX)
		for (int j = i; j < MAX; j += i)
			divisors[j].pb(i);
	forab (i, 1, MAX)
	{
		sum[i] = i;
		for (auto d : divisors[i])
			if (d != i)
				sum[i] -= sum[d];
	}
	forn (i, n)
	{
		int l;
		scanf("%d", &l);
		for (auto d : divisors[l])
			cnt[d]++;
	}
	LL ans = 0;
	forab (i, 1, MAX)
	{
	    cur[i] = (c(cnt[i], k) * 1ll * sum[i]) % MOD;
		ans += cur[i];
	}
	ans %= MOD;
	forn (qq, q)
	{
		int l;
		scanf("%d", &l);
		for (auto d : divisors[l])
		{
			sub(ans, cur[d]);
            cnt[d]++;
            if (cnt[d] == k)
            	cur[d] = sum[d];
            if (cnt[d] > k)
            {
            	cur[d] = ((cur[d] * 1ll * cnt[d]) % MOD * 1ll * obr_ch[cnt[d] - k]) % MOD;
        	}
        	add(ans, cur[d]);
        	//printf("%d %d " I64 "\n", d, cur[d], ans);
        }
        printf(I64 "\n", ans);
	}
	
	return 0;
}