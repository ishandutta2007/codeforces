#include <bits/stdc++.h>
        
using namespace std;
        
        
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
        
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
         
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define size(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
        
const int inf = 5e9 + 7;
const int max_n = 51, max_m = 1 << 16;

int n, m, k;
int a[max_n][max_m], dp[max_n][max_m];


void scan() {
	cin >> n >> m >> k;

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++)
			cin >> a[i][j], a[i][j] = a[i][j] + (j == 0 ? 0 : a[i][j - 1]);
	}
}

int get(int id, int l, int r) {
	return a[id][r] - (l == 0 ? 0 : a[id][l - 1]);
}


int mx[2 * max_m], push[2 * max_m];



void upd(int v, int x) {
	push[v] += x;
	mx[v] += x;
}

void pushing(int v) {
	upd(v * 2, push[v]);
	upd(v * 2 + 1, push[v]);
	push[v] = 0;
}

int segget() {
	return mx[1];
}

void segset(int l, int r, int x, int v = 1, int tl = 0, int tr = max_m - 1) {
	if (tl > r || tr < l) return;
	if (tl >= l && tr <= r) {
		upd(v, x);
		return;
	}
	pushing(v);
	int mid = (tl + tr) / 2;
	segset(l, r, x, v * 2, tl, mid);
	segset(l, r, x, v * 2 + 1, mid + 1, tr);
	mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
}


void build(int id) {
	for(int i = 1;i < 2 * max_m;i++)
		mx[i] = push[i] = 0;
	for(int i = 0;i < m;i++)
		segset(i, i, dp[id][i]);
}


void solve() {
	scan();

	vector<int> pref(m), suf(m + k);
	for(int i = 0;i < n;i++) {
		if (i != 0) build(i - 1);

		for(int j = -k;j < m + k;j++) {
			if (i != 0) {
				if (j - 1 >= 0 && j - 1 < m) segset(j - k, j - 1, get(i, j - 1, j - 1));
				if (j + k - 1 >= 0 && j + k - 1 < m) segset(j, j + k - 1, -get(i, j + k - 1, j + k - 1));

				if (j >= 0 && j < m) {
					dp[i][j] = segget();
				}
			}

			if (j >= 0 && j < m) dp[i][j] += get(i, j, j + k - 1) + get(i + 1, j, j + k - 1);
		}

		for(int j = 0;j < m;j++)
			pref[j] = max(dp[i][j], (j == 0 ? 0 : pref[j - 1]));

		for(int j = m - 1;j >= 0;j--)
			suf[j] = max(dp[i][j], suf[j + 1]);

	}

	int res = pref[m - 1];

	cout << res << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}