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

const int MAX_N = 2e5 + 5, MAX_F = 150;

vi v[MAX_N];
int a[MAX_N];
set<int> ind[MAX_N];
int mult[MAX_F][MAX_F];
int was[MAX_F];

vi mul(const vi& a, const vi&b) {
	vi v(sz(a));
	forn (i, sz(a))
		v[i] = b[a[i]];
	return v;
}

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        size_t seed = 0;
        for (int i : v) {
            seed = seed * 5 + i;
        }
        return seed;
    }
};

unordered_map<vi, int, VectorHash> m;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, k;
	scanf("%d%d", &n, &k);
	
	vector<int> id(k);
	forn (j, k)
		id[j] = j;
	
	vi b = id;
	int cur = 0;
	do {
		m[b] = cur++;
	} while (next_permutation(all(b)));
	
	b = id;
	int ind1 = 0;
	do {
		vi c = id;
		int ind2 = 0;
		do {
			mult[ind1][ind2] = m[mul(b, c)];
			ind2++;
		} while (next_permutation(all(c)));
		ind1++;
	} while (next_permutation(all(b)));	
	
	forn (i, n) {
		v[i].resize(k);
		forn (j, k)
			scanf("%d", &v[i][j]), v[i][j]--;
		a[i] = m[v[i]];
		ind[a[i]].insert(i);
	}

	ll ans = 0;
	set<int> indices;
	vi perms, curPerms, newPerms;
	vi generators;
	
	vi fact(k + 1);
	fact[0] = 1;
	forn (i, k)
		fact[i + 1] = fact[i] * (i + 1);
	
	forn (j, fact[k])
		if (sz(ind[j]))
			indices.insert(*ind[j].begin());

	forn (i, n) {
		perms.clear();
		perms.pb(0); // id
		forn (j, MAX_F)
			was[j] = 0;
		was[0] = 1;
		generators.clear();
		int lastInd = i;

		for (int ind : indices) {
			ans += (ind - lastInd) * 1ll * sz(perms);
			lastInd = ind;
			if (!was[a[ind]]) {
				generators.pb(a[ind]);
				curPerms = perms;
				while (sz(curPerms)) {
					newPerms.clear();
					for (int perm : curPerms) {
						for (int gen : generators) {
							int newPerm = mult[perm][gen];
							if (!was[newPerm]) {
								was[newPerm] = 1;
								perms.pb(newPerm);
								newPerms.pb(newPerm);
							}
						}
					}
					curPerms = newPerms;
					if (sz(perms) == fact[k])
						break;
				}
			}
		}
		ans += (n - lastInd) * 1ll * sz(perms); 

		ind[a[i]].erase(i);
		indices.erase(i);
		if (sz(ind[a[i]]))
			indices.insert(*ind[a[i]].begin());
	}
	cout << ans;
	return 0;
}