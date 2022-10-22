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
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> K;
	vector<int>a(K + 1);
	vector<int>c(K + 1);
	cin >> a[0] >> c[0];
	vector<int>depth(K + 1);
	vector<vector<int>>par(K + 1, vector<int>(20, -1));
	for (int loop = 1; loop <= K; loop++) {
		int q;
		cin >> q;
		if (q == 1) {
			cin >> par[loop][0];
			depth[loop] = depth[par[loop][0]] + 1;
			cin >> a[loop] >> c[loop];
			int idx = par[loop][0];
			for (int i = 1; i < 20; i++) {
				if (idx == -1)break;
				par[loop][i] = par[idx][i - 1];
				idx = par[loop][i];
			}
		}
		else {
			int v, w;
			cin >> v >> w;
			int buy = 0;
			long long int cost = 0;
			while (w && a[v]) {
				int idx = v;
				for (int i = 19; i >= 0; i--) {
					if (par[idx][i] != -1 && a[par[idx][i]]) {
						idx = par[idx][i];
					}
				}
				int use = min(a[idx], w);
				a[idx] -= use;
				w -= use;
				buy += use;
				cost += 1LL * c[idx] * use;
			}
			cout << buy << " " << cost << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}