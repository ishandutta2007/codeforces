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

vi w1, w2;

void getAnswer(const string &a, const string &b, bool sw, vector<pii> &ans) {
 	int n = sz(a);
 	int m = sz(b);
 	w1.clear();
 	w2.clear();
 	if (n > 0 && ((a[n - 1] == 'a' && sw) || (a[n - 1] == 'b' && !sw)))
	 	w1.pb(n);
 	for (int i = n - 2; i >= 0; i--)
 		if (a[i] != a[i + 1])
 			w1.pb(i + 1);
 	if (m > 0 && ((b[m - 1] == 'b' && sw) || (b[m - 1] == 'a' && !sw)))
	 	w2.pb(m);
 	for (int i = m - 2; i >= 0; i--)
 		if (b[i] != b[i + 1])
 			w2.pb(i + 1);
 	int k = max(0, sz(w2) - sz(w1));
	forn (i, k)
		w1.pb(0);			
	k = max(0, sz(w1) - sz(w2));
	forn (i, k)
		w2.pb(0);
	int curSw = 0;
	forn (i, sz(w1)) {
	    if (!curSw) {
	    	ans.pb(mp(w1[i], w2[i]));
	    } else {
	    	ans.pb(mp(w2[i], w1[i])); 
	    }
		curSw ^= 1;
	}	
}

void relax(vector<pii> &ans, const vector<pii> &curAns, bool &was) {
 	if (!was) {
 		ans = curAns;
		was = 1;
		return;
	}
	if (sz(curAns) < sz(ans)) {
	 	ans = curAns;
   	}
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	string s, t;
	cin >> s;
	cin >> t;
	int n = sz(s);
	int m = sz(t);	

	vector<pii> ans;
	bool was = 0;
	string r1, r2;
	vector<pii> curAns;
	forn (i, 2) {
		vi v1, v2;
		if (n > 0 && ((s[n - 1] == 'a' && i) || (s[n - 1] == 'b' && !i)))
		 	v1.pb(n);
	 	for (int j = n - 2; j >= 0; j--)
 			if (s[j] != s[j + 1])
 				v1.pb(j + 1);
	 	if (m > 0 && ((t[m - 1] == 'b' && i) || (t[m - 1] == 'a' && !i)))
		 	v2.pb(m);
	 	for (int j = m - 2; j >= 0; j--)
 			if (t[j] != t[j + 1])
 				v2.pb(j + 1);
	 	v1.pb(0);
	 	v2.pb(0);
	 	if (sz(v1) <= sz(v2)) {
	 	 	int k = (sz(v2) - sz(v1)) / 2;
	 	 	forn (j, 2) {
	 	 		forab (g, k - 2, k + 3) {
	 	 			if (g >= 0 && g < sz(v2) && j < sz(v1)) {
	 	 		 		curAns.clear(); 	
	 	 		 		int x = v1[sz(v1) - 1 - j], y = v2[sz(v2) - 1 - g];
	 	 		 		if (x != 0 || y != 0)
	 	 		 			curAns.pb(mp(x, y));
						r1.clear();
						r2.clear();
						forn (z, y)
							r1.pb(t[z]);
						forab (z, x, n)
							r1.pb(s[z]);						
						forn (z, x)
							r2.pb(s[z]);
						forab (z, y, m)
							r2.pb(t[z]);
						getAnswer(r1, r2, i, curAns);  					
			 	 		relax(ans, curAns, was);	 	
	 	 		 	}
	 	 		}
	 	 	}
	 	}
	 	else {
	 	 	int k = (sz(v1) - sz(v2)) / 2;
	 	 	forn (j, 2) {
	 	 		forab (g, k - 2, k + 3) {
	 	 		 	if (g >= 0 && g < sz(v1) && j < sz(v2)) {
	 	 		 		curAns.clear(); 	
	 	 		 		int x = v1[sz(v1) - 1 - g], y = v2[sz(v2) - 1 - j];
	 	 		 		if (x != 0 || y != 0)
	 	 		 			curAns.pb(mp(x, y));
						r1.clear();
						r2.clear();
						forn (z, y)
							r1.pb(t[z]);
						forab (z, x, n)
							r1.pb(s[z]);						
						forn (z, x)
							r2.pb(s[z]);
						forab (z, y, m)
							r2.pb(t[z]);
						getAnswer(r1, r2, i, curAns);  					
			 	 		relax(ans, curAns, was);
	 	 		 	}
	 	 		}
	 	 	}
	 	}
	}
	printf("%d\n", sz(ans));
	for (auto np : ans)
		printf("%d %d\n", np.fs, np.sc);
	return 0;
}