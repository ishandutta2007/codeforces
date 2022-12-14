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

const int MAX_N = 1e5 + 5;

map<pair<string, int>, vector<pair<string, int>>> go;
set<string> names;
map<string, vi> versions;
map<pair<string, int>, int> d;
set<pair<string, int>> ans;
vector<pair<string, int>> cur, nxt, tmpNxt;
set<string> used;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	cin >> n;
	pair<string, int> start;
	forn (i, n) {
		string t;
		int v, k;
        cin >> t >> v >> k;
        versions[t].pb(v);
        names.insert(t);
        d[mp(t, v)] = n + 1;
        if (i == 0)
        	start = mp(t, v);
   		forn (j, k) {
   			string s;
   			int sv;
   		 	cin >> s >> sv;
   		 	go[mp(t, v)].pb(mp(s, sv));
   		}
   	}	
   	d[start] = 0;
   	cur = {start};
   	while (sz(cur)) {
   		nxt.clear();
   	    for (auto &np : cur)
   	    	used.insert(np.fs);
   	    for (auto &np : cur) {
    		for (auto nxtNp : go[np]) {
				if (d[nxtNp] > d[np] + 1 && !used.count(nxtNp.fs)) {
					d[nxtNp] = d[np] + 1;
					nxt.pb(nxtNp);
				}	
			}	
   		}
   		sort(all(nxt));
   		tmpNxt.clear();
   		forn (i, sz(nxt))
   		 	if (i == sz(nxt) - 1 || nxt[i].fs != nxt[i + 1].fs)
   		 		tmpNxt.pb(nxt[i]);   	
   		cur = tmpNxt;
   		for (auto &np : cur)
   			ans.insert(np);
   	}
   	printf("%d\n", sz(ans));
   	for (auto &np : ans)
		cout << np.fs << " " << np.sc << "\n";
	return 0;
}