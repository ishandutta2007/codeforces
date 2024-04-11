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

const int MAX_N = 305;

string s[MAX_N][MAX_N], t[MAX_N][MAX_N];
int cnt0[MAX_N], cnt1[MAX_N];
int n, m;

struct Move {
 	int x_1, y_1, x_2, y_2;
 	Move(int x_1_, int y_1_, int x_2_, int y_2_): x_1(x_1_), y_1(y_1_), x_2(x_2_), y_2(y_2_) {}
 	Move() {}
};

vector<Move> ans;

void go0(int i, int j) {
	if (i == 0 && j == 0) {
		ans.pb(Move(0, 0, 0, m - 1));
		ans.pb(Move(0, m - 1, 0, 0));
	}
 	if (j != 0)
 		ans.pb(Move(0, 0, 0, j));
 	if (i != 0)
 		ans.pb(Move(0, j, i, j));
}

void go1(int i, int j) {
	if (i == n - 1 && j == m - 1) {
		ans.pb(Move(n - 1, m - 1, 0, m - 1));
		ans.pb(Move(0, m - 1, n - 1, m - 1));
	}
 	if (i != n - 1)
 		ans.pb(Move(n - 1, m - 1, i, m - 1));
 	if (j != m - 1)
 		ans.pb(Move(i, m - 1, i, j));
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	scanf("%d%d", &n, &m);
	forn (i, n) {
	 	forn (j, m)
	 		cin >> s[i][j];
	}
	forn (i, n) {
	 	forn (j, m)
	 		cin >> t[i][j];
	}
	forab (i, 1, n - 1)
		forn (j, m) {
			int len = sz(s[i][j]);
	    	fornr (g, len) {
				if (s[i][j][g] == '0')
					ans.pb(Move(i, j, 0, j)), cnt0[j]++;
				else
					ans.pb(Move(i, j, n - 1, j)), cnt1[j]++;
			}
		}

	forn (j, m) {
		int len = sz(s[0][j]);
	    fornr (g, len) 
			if (s[0][j][g] == '1')
				ans.pb(Move(0, j, n - 1, j)), cnt1[j]++;
			else {
			 	if (j != 0)
			 		ans.pb(Move(0, j, 0, 0)), cnt0[0]++;
			 	else
			 		ans.pb(Move(0, 0, 0, m - 1)), cnt0[m - 1]++;
			}
	} 

	fornr (j, m) {
		int len = sz(s[n - 1][j]);
	    fornr (g, len)
			if (s[n - 1][j][g] == '0')
				ans.pb(Move(n - 1, j, 0, j)), cnt0[j]++;
			else {
			 	if (j != m - 1)
			 		ans.pb(Move(n - 1, j, n - 1, m - 1)), cnt1[m - 1]++;
			 	else
			 		ans.pb(Move(n - 1, m - 1, n - 1, 0)), cnt1[0]++;
			}
	} 
	forab (i, 1, m)
		forn (g, cnt0[i])
			ans.pb(Move(0, i, 0, 0));
	forn (i, m - 1)
		forn (g, cnt1[i])
			ans.pb(Move(n - 1, i, n - 1, m - 1));

	vector<pii> v;	        	
	forab (i, 1, n)
		forn (j, m - 1) {
			v.pb(mp(i, j));
		}
	forab (j, 1, m - 1)
		v.pb(mp(0, j));
	forab (i, 1, n - 1)
		v.pb(mp(i, m - 1));
	v.pb(mp(0, 0));
	v.pb(mp(n - 1, m - 1));
	v.pb(mp(0, m - 1));
	for (auto np : v) {
	 	int x = np.fs, y = np.sc;
	 	int len = sz(t[x][y]);
	    fornr (g, len) {
	    	if (t[x][y][g] == '0')
	    		go0(x, y);
	    	else 
	    		go1(x, y);
		}	    
	}

	printf("%d\n", sz(ans));
	for (auto mov : ans) {
		printf("%d %d %d %d\n", mov.x_1 + 1, mov.y_1 + 1, mov.x_2 + 1, mov.y_2 + 1);
	}

	return 0;
}