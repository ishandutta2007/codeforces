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
//#include <atcoder/all>

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr long long int MOD = 998244353;
constexpr int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int p[200001] = {};

void Solve() {
	random_device rd;
	mt19937_64 mt(rd());

	cin >> N;
	if (N > 100) {
		vector<long long>v(N + 1);
		long long g = 0;
		vector<int>q;
		for (int i = 2; i <= N; i++) {
			q.push_back(i);
		}
		shuffle(q.begin(), q.end(), mt);
		for (int i = 0; i < min(5000,(int)q.size()); i++) {
			int idx = q[i];
			cout << "? 1 " << idx << endl;
			cin >> v[idx];
			g = gcd(g, v[idx]);
		}
		vector<long long>ans(N + 1);
		int idx = -1;
		int num = 0;
		{
			for (int i = 2; i <= N; i++) {
				long long gg = v[i] / g;
				if (v[i] && gg <= 200000 && p[gg] == gg && num < gg) {
					num = gg;
					idx = i;
				}
			}
			ans[idx] = num;
		}
		if (idx == -1) {
			idx = 1;
			ans[idx] = g;
		}
		for (int i = 1; i <= N; i++) {
			if (idx != i) {
				cout << "? " << i << " " << idx << endl;
				cin >> ans[i];
				ans[i] /= ans[idx];
			}
		}
		set<int>st;
		for (int i = 1; i <= N; i++) {
			st.insert(ans[i]);
		}
		if (st.size() < N)assert(0);
		cout << "!";
		for (int i = 1; i <= N; i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
	else {
		vector<vector<long long>>box(N + 1, vector<long long>(N + 1));
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				cout << "? " << i << " " << j << endl;
				cin >> box[i][j];
				box[j][i] = box[i][j];
			}
		}
		vector<long long>g(N + 1);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				g[i] = gcd(g[i], box[i][j]);
			}
		}
		int mn = *min_element(g.begin()+1, g.end());
		vector<int>ans(N + 1);
		set<int>st;
		for (int i = 1; i <= N; i++) {
			if (g[i] < mn + N) {
				ans[i] = g[i];
			}
			else {
				ans[i] = g[i] / 2;
			}
			st.insert(ans[i]);
		}
		if (*min_element(ans.begin() + 1, ans.end()) < mn || *max_element(ans.begin(), ans.end()) >= mn + N || st.size() < N) {
			assert(0);
		}
		cout << "!";
		for (int i = 1; i <= N; i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (long long i = 2; i <= 200000; i++) {
		if (p[i])continue;
		p[i] = i;
		for (long long j = i * i; j <= 200000; j += i) {
			p[j] = i;
		}
	}
	cin >> T;
	while (T--) {
		Solve();
	}
}