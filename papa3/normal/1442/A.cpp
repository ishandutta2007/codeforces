#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

template<class C> void mini(C &a5, C b5) { a5 = min(a5, b5); }
template<class C> void maxi(C &a5, C b5) { a5 = max(a5, b5); }

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;

struct Algo {
	int n;
	vector<int> tab, l, r;
	
	Algo() {
		cin >> n;
		tab.resize(n + 10);
		l.resize(n + 10);
		r.resize(n + 10);
		
		for (int i = 1; i <= n; i++) {
			cin >> tab[i];
		}
		tab[0] = tab[n + 1] = INF;
		
		for (int i = 1; i <= n; i++) {
			l[i] = max(0LL, tab[i] - tab[i + 1]);
			r[i] = max(0LL, tab[i] - tab[i - 1]);
			cerr << l[i] << "," << r[i] << " ";;
		}
		
		int sum = 0;
		for (int i = n; i > 0; i--) {
			sum += l[i];
			tab[i] -= sum;
		}
		
		sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += r[i];
			tab[i] -= sum;
		}
		
		for (int i = 1; i <= n; i++) {
			if (tab[i] < 0) {
				cout << "NO\n";
				return;
			}
		}
		
		cout << "YES\n";
	}
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
		Algo p;
	}
    
    return 0;
}/*

*/