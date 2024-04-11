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
//#define all(_v) _v.begin(), _v.end()
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int max_n = 1e5 + 3, max_k = 8;

struct req {
	int x, id, type;
	req() {}
	req(int x, int id, int type) : x(x), id(id), type(type) {}
};

int n;
vector<req> a;
int bit[max_n];

int use = 0;
int dp1[1 << max_k], dp2[1 << max_k];

void scan() {
	int m, k;
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++) {
		int l, r;
		cin >> l >> r;
		a.emplace_back(req(l, i, 1));
		a.emplace_back(req(r + 1, i, -1));
	}
	sort(a.begin(), a.end(), [](auto v1, auto v2) {return mp(v1.x, v1.type) < mp(v2.x, v2.type);});
}

void solve() {
	scan();
	int lst = 0;

	for(req v : a) {
		if (v.type == 1) {
			for(int i = 0;i < max_k;i++) {
				if (!((use >> i) & 1)) {
					bit[v.id] = i;
					break;
				}
			}
		}

		int num = (1 << bit[v.id]);

		for(int m = 0;m < (1 << max_k);m++) {
			if ((m & use) != m) continue;
			int add = ((__builtin_popcount(m) & 1) ? v.x - lst : 0);
			if (v.type == 1) {
				chkmax(dp2[m], dp1[m] + add);
				chkmax(dp2[m | num], dp1[m] + add);
			}else {
				chkmax(dp2[m & ~num], dp1[m] + add);
			}
		}

		if (v.type == 1) use |= num;
		else use &= ~num;

		lst = v.x;

		for(int i = 0;i < (1 << max_k);i++)
			dp1[i] = 0;
		swap(dp1, dp2);
	}

	int res = 0;
	for(int i = 0;i < (1 << max_k);i++)
		chkmax(res, dp1[i]);

	cout << res << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}