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
const int mod = 998244353;

struct Algo {
	int n, k;
	vector<int> czy;
	vector<int> a, b;
	vector<int> pos;
	
	Algo() {
		cin >> n >> k;
		a.resize(n + 10);
		b.resize(n + 10);
		pos.resize(n + 10);
		czy.resize(n + 10, 1);
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			pos[a[i]] = i;
		}
		
		
		for (int i = 1; i <= k; i++) {
			cin >> b[i];
			b[i] = pos[b[i]];
			czy[b[i]] = 0;
		}
		czy[0] = czy[n + 1] = 0;
		
		//for (int i = 0; i <= n + 1; i++) cerr << czy[i] << " ";
		cerr << endl;
		
		int res = 1;
		for (int j = 1; j <= k; j++) {
			int i = b[j];
			cerr << i << " " << czy[i - 1] << " " << czy[i + 1] << endl;
			res = (res * (czy[i - 1] + czy[i + 1])) % mod;
			czy[i] = 1;
		}
		cout << res << "\n";
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
1
5 3
1 2 3 4 5
3 2 5

3
5 3
1 2 3 4 5
3 2 5
4 3
4 3 2 1
4 3 1
7 4
1 4 7 3 6 2 5
3 2 4 5

*/