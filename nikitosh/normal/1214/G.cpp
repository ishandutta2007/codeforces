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

const int MAX_N = 2048;

int a[MAX_N];
bitset<MAX_N> b[MAX_N], ones[MAX_N], xo;

bool bad(int i, int j) {
	return i != -1 && j != -1 && (b[i] & b[j]) != b[i];
}

void getAns(int i, int j) {
	if (i > j)
		swap(i, j);
	xo = b[i] & b[j];
	int ind1 = (b[i] ^ xo)._Find_first(), ind2 = (b[j] ^ xo)._Find_first();
	if (ind1 > ind2)
		swap(ind1, ind2);
	cout << i + 1 << " " << ind1 + 1 << " " << j + 1 << " " << ind2 + 1 << "\n";
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	set<pii> s, pairs;
	int n, m, q;
	cin >> n >> m >> q;
	forn (i, n) 
		s.insert(mp(0, i));
	s.insert(mp(-1, -1));
	s.insert(mp(m + 1, -1));
	ones[0] = 0;
	forn (i, m) {
		ones[i + 1] = ones[i];
		ones[i + 1][i] = 1;
	}
	forn (qq, q) {
		int i, l, r;
		cin >> i >> l >> r;
		i--;
		auto it = s.find(mp(a[i], i));
		auto prev = it, nxt = it;
		prev--, nxt++;
		if (pairs.count(mp(prev->sc, it->sc)))
			pairs.erase(mp(prev->sc, it->sc));
		if (pairs.count(mp(it->sc, nxt->sc)))
			pairs.erase(mp(it->sc, nxt->sc));
		if (bad(prev->sc, nxt->sc))
			pairs.insert(mp(prev->sc, nxt->sc));
		s.erase(it);
		b[i] ^= ones[r] ^ ones[l - 1];
		a[i] = b[i].count();
		it = s.insert(mp(a[i], i)).fs;
		prev = it, nxt = it;
		prev--, nxt++;
		if (pairs.count(mp(prev->sc, nxt->sc)))
			pairs.erase(mp(prev->sc, nxt->sc));
		if (bad(prev->sc, it->sc))
			pairs.insert(mp(prev->sc, it->sc));
		if (bad(it->sc, nxt->sc))
			pairs.insert(mp(it->sc, nxt->sc));
	
		if (pairs.empty())
			cout << "-1\n";
		else
			getAns(pairs.begin()->fs, pairs.begin()->sc);	
	}		

	return 0;
}