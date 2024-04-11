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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<long long int>v(N);
	for (auto& i : v)cin >> i;
	vector<long long int>l(N);
	vector<long long int>r(N);
	stack<pair<long long int, long long int>>st;
	l[0] = v[0];
	st.push({ v[0],1 });
	for (int i = 1; i < N; i++) {
		pair<long long int, long long int>nx;
		nx = { v[i],1 };
		l[i] = l[i - 1];
		while (!st.empty() && st.top().first >= nx.first) {
			l[i] -= st.top().first * st.top().second;
			nx.second += st.top().second;
			st.pop();
		}
		l[i] += nx.first * nx.second;
		st.push(nx);
	}
	while (!st.empty())st.pop();
	r[N - 1] = v[N - 1];
	st.push({ v[N - 1],1 });
	for (int i = N - 2; i >= 0; i--) {
		pair<long long int, long long int>nx;
		nx = { v[i],1 };
		r[i] = r[i + 1];
		while (!st.empty() && st.top().first >= nx.first) {
			r[i] -= st.top().first * st.top().second;
			nx.second += st.top().second;
			st.pop();
		}
		r[i] += nx.first * nx.second;
		st.push(nx);
	}
	int idx = 0;
	for (int i = 0; i < N; i++) {
		if (l[i] + r[i]-v[i] > l[idx] + r[idx]-v[idx]) {
			idx = i;
		}
	}
	vector<long long int>ret(N);
	auto i = idx;
	long long int mx = v[i];
	for (int j = i; j >= 0; j--) {
		ret[j] = min(mx, v[j]);
		mx = min(mx, v[j]);
	}
	mx = v[i];
	for (int j = i; j < N; j++) {
		ret[j] = min(mx, v[j]);
		mx = min(mx, v[j]);
	}
	for (auto i : ret)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
//	cin >> T;
	while (T--) {
		Solve();
	}
}