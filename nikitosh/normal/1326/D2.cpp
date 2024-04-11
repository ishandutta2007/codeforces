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
  
const int N = 1e6 + 5;

int a0[N], a1[N];  
  
void manaker(const string& s, int *z0, int *z1) {
	int n = sz(s);
	forn (t, 2) {
		int *z = t ? z1 : z0, l = -1, r = -1; // [l..r]
		forn (i, n - t) {
			int k = 0;
			if (r > i + t) {
				int j = l + (r - i - t);
				k = min(z[j], j - l);
			}
			while (i - k >= 0 && i + k + t < n && s[i - k] == s[i + k + t])
				k++;
			z[i] = k;
			if (k && i + k + t > r)
				l = i - k + 1, r = i + k + t - 1;
		}
	}
}  
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	string s;
	int tn;
	cin >> tn;
	forn (tt, tn) {
		cin >> s;
		int n = sz(s), lcp = 0;
		forn (i, n) {
			if (s[i] == s[n - i - 1])
				lcp++;
			else
				break;
		}
		forn (i, n + 1)
			a0[i] = a1[i] = 0;
		manaker(s, a0, a1);
		int ans = 1, pr = 0;
		pii seg = mp(0, 1);
		if (ans < 2 * lcp) {
			ans = 2 * lcp;
			pr = lcp, seg = mp(0, 0);
		}
		forn (i, n) {
			int l = i - a0[i] + 1, r = i + a0[i] - 1;
			int dist = min(l, n - 1 - r);
			if (lcp >= dist && ans < 2 * dist + r - l + 1) {
				ans = 2 * dist + r - l + 1;
				pr = dist, seg = mp(l, r + 1);
			}
		}
		forn (i, n) {
			int l = i - a1[i] + 1, r = i + a1[i];
			int dist = min(l, n - 1 - r);
			if (lcp >= dist && ans < 2 * dist + r - l + 1) {
				ans = 2 * dist + r - l + 1;
				pr = dist, seg = mp(l, r + 1);
			}
		}
		forn (i, pr)
			cout << s[i];
		if (pr != n) {
			forab (i, seg.fst, seg.snd)
				cout << s[i];
			forab (i, n - pr, n)
				cout << s[i];
		}
		cout << "\n";
	}
	
	return 0;
}