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

const int MAX_N = 2005;

string s[MAX_N], t[MAX_N], a[MAX_N], b[MAX_N], ans[MAX_N], q[MAX_N * 2];
map<string, vi> was;
set<string> wasBfs;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n) {
	 	cin >> s[i] >> t[i];
		a[i] = s[i].substr(0, 3);
		b[i] = s[i].substr(0, 2) + t[i][0];
		was[a[i]].pb(i);
		ans[i] = a[i];
	}
	int head = 0, tail = 0;
	for (auto &np : was) {
	 	vi v = np.sc;
	 	if (sz(v) > 1) {
	 	 	q[tail++] = np.fs;
	 	 	wasBfs.insert(np.fs);
	 	}
	}	
	while (tail > head) {
	 	string r = q[head++];
		vi v = was[r];
		for (int ind : v) {
			ans[ind] = b[ind];
			if (!wasBfs.count(b[ind])) {
			    wasBfs.insert(b[ind]);
				q[tail++] = b[ind];
			}
	   	}
	}
	set<string> answers;
	forn (i, n)
		answers.insert(ans[i]);
	if (sz(answers) != n) {
	 	puts("NO");
	} else {
	 	puts("YES");
	 	forn (i, n)
	 		cout << ans[i] << "\n";
	}
	return 0;
}