#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MAX_N = 1e6 + 5;
const int P = 239017;
int MOD1, MOD2;

char s[MAX_N], r[MAX_N];
int n;	

int add(int a, int mod) {
 	return a >= mod ? a - mod : a;
}

int sub(int a, int mod) {
 	return a < 0 ? a + mod : a;
}

struct Hash {
	int p, q;
	Hash() = default;
	Hash(int _p): p(_p), q(_p) {}
	Hash(int _p, int _q): p(_p), q(_q) {}
	Hash operator+(const Hash &h) {
	 	return Hash(add(p + h.p, MOD1), add(q + h.q, MOD2));
	}
	Hash operator*(const Hash &h) {
	 	return Hash((p * 1ll * h.p) % MOD1, (q * 1ll * h.q) % MOD2);
	}
	bool operator==(const Hash &h) {
	 	return p == h.p && q == h.q;
	}
	Hash operator-(const Hash &h) {
	 	return Hash(sub(p - h.p, MOD1), sub(q - h.q, MOD2));
	}
};

Hash ps[MAX_N], h[MAX_N];

Hash getHash(int l, int r) {
 	return (h[r] - h[l]) * ps[n - r + 1];
}

bool isPrime(int k) {
 	for (int i = 2; i * 1ll * i <= k; i++) 
 		if (k % i == 0)
 			return 0;
	return 1;
}
  	
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	srand(time(0));
	vi v;
	forab (i, 1e9, 1e9 + 200) 
		if (isPrime(i))
			v.pb(i);
	set<int> st;
	while(sz(st) < 2) {
		st.insert(rand() % sz(v));
	}
	MOD1 = v[*st.begin()], MOD2 = v[*(++st.begin())];

	gets(r);
	gets(s);
	n = strlen(s);
	ps[0].p = ps[0].q = 1;
	forn (i, MAX_N - 1)
		ps[i + 1] = ps[i] * P;
    h[0] = 0;
	forn (i, n)
		h[i + 1] = h[i] + ps[i] * s[i];


	int k = strlen(r);
	int cnt[2];
	cnt[0] = cnt[1] = 0;
	forn (i, k) {
		cnt[r[i] - '0']++;
	}
	int ans = 0;
	forab (i, 1, n + 1) {
		ll lenFirst = i * 1ll * cnt[r[0] - '0'];
		if (lenFirst >= n)
			break;
		if ((n - lenFirst) % cnt[!(r[0] - '0')] != 0) 
			continue;
		int j = (n - lenFirst) / cnt[!(r[0] - '0')];
		int was[2];
		was[0] = was[1] = 0;
		Hash has[2]; 
		int curInd = 0;
		bool ok = 1;
		forn (g, k) {
			int curLen = i;
			if (r[g] != r[0])
				curLen = j;
			if (was[r[g] - '0'] == 0) {
			 	was[r[g] - '0'] = 1;
			 	has[r[g] - '0'] = getHash(curInd, curInd + curLen);
		 	} else {
		 		if (!(getHash(curInd, curInd + curLen) == has[r[g] - '0'])) {
		 		 	ok = 0;
		 		 	break;
		 		}
		 	}
		 	curInd += curLen;
		}
		if (ok && !(has[0] == has[1])) {
			ans++;
//			printf("%d\n", i);
		}
	}
	printf("%d\n", ans);
	return 0;
}