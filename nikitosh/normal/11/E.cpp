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
  
inline int prev(int ind, int len) {
	ind--;
	return ind < 0 ? ind + len : ind;
}  
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string s;
	cin >> s;
	int n = sz(s);
	string t;
	int pos = 0;
	vi v;
	string need = "LR";
	forn (i, n) {
		if (s[i] != 'X' && s[i] != need[sz(t) % 2]) {
			t += 'X';
			if (s[i] != s[prev(i, n)])
				v.pb(pos);
		}
		if (s[i] != 'X')
			pos++;
		t += s[i];
	}
	if (sz(t) % 2) {
		if (s[0] != s[n - 1] || s[0] == 'R')
			v.pb(pos);
		t += 'X';
	}
	int m = sz(t);
 	int match = 0, len = m;
 	forn (i, m) {
 		match += (t[i] != 'X' && t[i] == need[i % 2]);
 	}
 	forn (i, sz(v) - 1) {
 		if (2 * match > len && v[i] == v[i + 1] - 1)
 			match--, len -= 2, i++;
 	}
 	int r = match * 100000000ll / len;
 	printf("%d.%06d", r / 1000000, r % 1000000);
	return 0;
}