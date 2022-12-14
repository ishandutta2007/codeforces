#include <bits/stdc++.h> 

using namespace std;
 
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

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
    cin.tie(0);
    ios_base::sync_with_stdio(0);

	int tn;
	cin >> tn;
	string s, t;
	vector<pii> ans;
	forn (tt, tn) {
		int n, k;
		cin >> n >> k;
		cin >> s;
		t.clear();
		forn (i, n / 2 - (k - 1))
			t += "(";
		forn (i, n / 2 - (k - 1))
			t += ")";
		forn (i, k - 1)
			t += "()";
		ans.clear();
		forn (i, n) {
		 	if (s[i] != t[i]) {
		 	 	forab (j, i, n)
		 	 		if (s[j] == t[i]) {
		 	 		 	ans.pb(mp(i + 1, j + 1));
		 	 		 	reverse(s.begin() + i, s.begin() + j + 1);
		 	 		 	break;
		 	 		}
		 	}
		}
		cout << sz(ans) << "\n";
		for (auto np : ans)
			cout << np.fst << " " << np.snd << "\n";
	}

	return 0;
}