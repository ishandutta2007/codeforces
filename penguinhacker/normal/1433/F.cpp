#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#define debug(x) cerr << "[" << #x << "] = [" << x << "]\n"

template<class A, class B> ostream& operator<< (ostream& out, pair<A, B> p) {
	return out << '[' << p.first << ", " << p.second << ']';
}

template<class T> ostream& operator<< (ostream& out, vector<T>& v) {
	out << '[';
	for (int i = 0; i < v.size(); ++i) {
		if (i > 0) {
			out << ", ";
		}
		out << v[i];
	}
	return out << ']';
}



const int INF = 1e9;
int n, m, k;
vector<int> dp;
vector<vector<int>> cur; //number selected, modulo class

void solve(vector<int> v) {
	cur.assign(m / 2 + 1, vector<int>(k, -INF));
	cur[0][0] = 0;
	for (int x : v) {
		for (int i = m / 2 - 1; i >= 0; --i) {
			for (int j = 0; j < k; ++j) {
				cur[i + 1][(j + x) % k] = max(cur[i + 1][(j + x) % k], cur[i][j] + x);
			}
		}
	}
	vector<int> best(k, -INF);
	for (int i = 0; i <= m / 2; ++i) {
		for (int j = 0; j < k; ++j) {
			best[j] = max(best[j], cur[i][j]);
		}
	}
	vector<int> nxt_dp = dp;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			nxt_dp[(i + j) % k] = max(nxt_dp[(i + j) % k], dp[i] + best[j]);
		}
	}
	swap(dp, nxt_dp);
	//debug(dp);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	dp.assign(k, -INF);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		vector<int> v(m);
		for (int j = 0; j < m; ++j) {
			cin >> v[j];
		}
		solve(v);
	}
	cout << dp[0];
	return 0;
}