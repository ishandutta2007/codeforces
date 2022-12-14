#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
 
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;

#define FNAME ""

const int MAX_N = 2e5 + 5;

int b[MAX_N], ans[MAX_N];
pii a[MAX_N];
vector<pii> queries[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n;
    forn (i, n) {
    	cin >> a[i].fst, a[i].snd = -i;
    	b[i] = a[i].fst;
    }	
    sort(a, a + n);
    reverse(a, a + n);
    cin >> q;
    forn (qq, q) {
    	int k, pos;
     	cin >> k >> pos;
     	queries[k].pb(mp(pos, qq));
    }
    ordered_set s;
	forn (i, n) {
		s.insert(-a[i].snd);
		for (auto np : queries[i + 1])
		 	ans[np.snd] = b[*s.find_by_order(np.fst - 1)];
    }
	forn (qq, q)
		cout << ans[qq] << "\n";	

	return 0;
}