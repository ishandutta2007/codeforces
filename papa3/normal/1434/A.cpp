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

int a[6];

struct moj {
	int b[6];
	int cur;
	
	moj(int x) {
		for (int i = 0; i < 6; i++) {
			b[i] = x - a[i];
		}
		sort(b, b + 6);
		cur = 0;
	}
	
	bool operator < (const moj & other) const {
		return b[cur] > other.b[other.cur];
	}
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	
	priority_queue<moj> kol;
	int ma = 0;
	int res = INF;
	
	int n;
	cin >> n;
	for (int x, i = 0; i < n; i++) {
		cin >> x;
		moj m(x);
		kol.push(m);
		maxi(ma, m.b[0]);
	}
	
	cerr << " " << ma << endl;
	
	while (true) {
		moj m = kol.top();
		kol.pop();
		mini(res, ma - m.b[m.cur]);
		if (++m.cur >= 6) {
			break;
		}
		kol.push(m);
		maxi(ma, m.b[m.cur]);
	cerr << " " << ma << endl;
	}
	
	cout << res;
	
    
    return 0;
}/*

*/