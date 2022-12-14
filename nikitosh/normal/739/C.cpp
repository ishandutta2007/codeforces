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
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N  = 3e5 + 5;

int a[MAX_N];
ll d[MAX_N];
set<pii> s;
multiset<int> lens;

void insert(int l, int r) {
	//printf("insert %d %d\n", l, r);
 	if (l >= r)
 		return;
 	s.insert(mp(l, r));
 	lens.insert(r - l);
}

void erase(pii np) {
	//printf("erase %d %d\n", np.fs, np.sc);
 	s.erase(np);
 	lens.erase(lens.find(np.sc - np.fs));
}

bool isOk(ll a, ll b) {
 	return a < 0 || (a > 0 && b > 0);
}

void update(int ind, int dlt) {
	ll newVal = d[ind] + dlt;
	if (d[ind] != 0) {
		auto it = --s.lower_bound(mp(ind + 1, -1));
		auto np = *it;
		erase(np);
		insert(np.fs, ind);
		insert(ind + 1, np.sc);
	}
	d[ind] = newVal;
	if (newVal == 0)
		return;
	int l = ind, r = ind + 1;
	auto it = s.lower_bound(mp(l, r));
	if (it != s.begin()) {
	 	it--;
	 	if (it->sc == ind && isOk(d[ind - 1], newVal)) 
	 		l = it->fs, erase(*it);
	}
	it = s.lower_bound(mp(l, r));
	if (it != s.end()) {
	 	if (it->fs == ind + 1 && isOk(newVal, d[ind + 1])) 
	 		r = it->sc, erase(*it);
	}
	insert(l, r);	
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &a[i]);
	forn (i, n)
		d[i] = a[i] - a[i + 1];
   	forn (i, n - 1) {
   	 	if (d[i] != 0) {
   	 	 	int it = i;
   	 	 	while (it < n - 1 && d[it] < 0)
   	 	 		it++;
   	 	 	while (it < n - 1 && d[it] > 0)
   	 	 		it++;
   	 	 	s.insert(mp(i, it));
   	 	 	lens.insert(it - i);
   	 	 	i = it - 1;
   	 	}
   	}
   	int q;
	scanf("%d", &q);
	forn (qq, q) {
		int l, r, dlt;
	 	scanf("%d%d%d", &l, &r, &dlt);
	 	l--, r--;
	 	if (l != 0)
	 		update(l - 1, -dlt);
	 	if (r != n - 1)
	 		update(r, dlt);
	 	if (sz(lens) == 0)
	 		printf("1\n");
	 	else
	 		printf("%d\n", *lens.rbegin() + 1);
	}

	return 0;
}