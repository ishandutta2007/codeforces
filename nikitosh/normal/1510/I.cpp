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
using dbl = double;

const int N = 1e4 + 5;
 
int cnt[N];

mt19937 rng(239);

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n = 10, m = 10;
	cin >> n >> m;
	string s;
	srand(239017);
	forn (qq, m) {
		cin >> s;
/*		s.clear();
		forn(i, n){ 
			s += char('0' + (rand() & 1));
		}*/
		int minn = cnt[0];
		forn (i, n) 
			minn = min(minn, cnt[i]);
		dbl votes[2] = {0, 0};
		forn (i, n) {
			int vote = s[i] - '0';
			votes[vote] += pow(0.9, cnt[i] - minn);
		}
//		cerr << votes[0] << " " << votes[1] << '\n';
		dbl r = (rng() % INT_MAX) * 1. / INT_MAX;
	//	cerr << r << '\n';
		r *= (votes[0] + votes[1]);
		if (r < votes[0]) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
		
		fflush(stdout);
		int k = rand() & 1;
		cin >> k;
		forn (i, n)
			if (s[i] - '0' != k)
				cnt[i]++;
	}
	
	return 0;
}