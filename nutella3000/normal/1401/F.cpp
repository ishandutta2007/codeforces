#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
        
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
         
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int max_n = (1 << 19), log_n = 19;

int n, q;
bool rev[log_n], sw[log_n];
int sum[2 * max_n];

void segset(int id, int x, int v = 1, int tl = 0, int tr = max_n - 1) {
	if (tl > id || tr < id) return;
	if (tl == id && tr == id) {
		sum[v] = x;
		return;
	}
	int mid = (tl + tr) / 2;
	segset(id, x, v * 2, tl, mid);
	segset(id, x, v * 2 + 1, mid + 1, tr);
	sum[v] = sum[v * 2] + sum[v * 2 + 1];
}

int segget(int l, int r, int v = 1, int tl = 0, int tr = max_n - 1) {
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return sum[v];
	int mid = (tl + tr) / 2;
	return segget(l, r, v * 2, tl, mid) + segget(l, r, v * 2 + 1, mid + 1, tr);
}

int get_id(int x) {
	for(int k = 0;k < log_n;k++) {
		
		if (rev[k]) x += (1 << k) - 1 - 2 * (x & ((1 << k) - 1));
		if (sw[k]) x ^= (1 << k);
	}
	return x;
}

void solve() {
	cin >> n >> q;
	n = 1 << n;
	for(int i = 0;i < n;i++) {
		int v;
		cin >> v;
		segset(i, v);
	}

	for(int it = 0;it < q;it++) {
		int t, x, k, l, r;
		cin >> t;
		if (t == 1) {
			cin >> x >> k;
			x--;
			segset(get_id(x), k);
		}
		if (t == 2) {
			cin >> k;
			rev[k] ^= 1;
		}
		if (t == 3) {
			cin >> k;
			sw[k] ^= 1;
		}
		if (t == 4) {
			cin >> l >> r;
			int res = 0;
			l--; r--;
			auto f = [&](int x) {
				if (x == 0) return (int)((1 << __lg(r)) - 1);
				return x | (x - 1);
			};
			auto h = [&](int x) {return x & (x + 1);};


			while(f(l) <= r) {
				//cout << "seg " << l << " " << f(l) << endl;
				int s = __lg(f(l) + 1 - l);
				int bl = get_id(l) >> s;
				//cout << "r " << (bl << s) << " " << ((bl + 1) << s) - 1 << endl;

				res += segget(bl << s, ((bl + 1) << s) - 1);
				l = f(l) + 1;
			}

			while(h(r) >= l) {
				//cout << "seg " << h(r) << " " << r << endl;
				
				int s = __lg(r - h(r) + 1);
				int bl = (get_id(r) >> s);
				//cout << "r " << (bl << s) << " " << ((bl + 1) << s) - 1 << endl;
				res += segget(bl << s, ((bl + 1) << s) - 1);

				r = h(r) - 1;
			}

			cout << res << endl;
		}
	}
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}