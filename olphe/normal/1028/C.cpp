#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

struct box {
	int l, r, u, d;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>l(N);
	vector<int>r(N);
	vector<int>u(N);
	vector<int>d(N);
	vector<box>v(N);
	for (int i = 0; i < N; i++) {
		cin >> l[i] >> d[i] >> r[i] >> u[i];
		v[i].l = l[i];
		v[i].r = r[i];
		v[i].u = u[i];
		v[i].d = d[i];
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	sort(u.begin(), u.end());
	sort(d.begin(), d.end());
	reverse(r.begin(), r.end());
	reverse(u.begin(), u.end());
	vector<int>w({ l[N - 2],r[N - 2],l[N - 1],r[N - 1] });
	vector<int>h({ u[N - 2],d[N - 2],u[N - 1],d[N - 1] });
	for (auto i : w) {
		for (auto j : h) {
			int cnt = 0;
			for (auto k : v) {
				if (i >= k.l&&i <= k.r&&j >= k.d&&j <= k.u)cnt++;
			}
			if (cnt >= N - 1) {
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	return 0;
}