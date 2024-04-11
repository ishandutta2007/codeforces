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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	vector<int>num(N + 2);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		num[v[i]]++;
		while (num[ans])ans++;
	}
	vector<int>w;
	vector<int>c(N + 2);
	int st = 0;
	while (st < N) {
		int amari = ans;
		int nx = ans;
		w.push_back(ans);
		do{
			c[v[st]]++;
			if (c[v[st]] == 1&&v[st]<nx)amari--;
			num[v[st]]--;
			if (num[v[st]] == 0)ans = min(ans,v[st]);
			st++;
		} while (amari);
		for (int i = 0; i < w.back(); i++)c[i] = 0;
	}
	cout << w.size() << endl;
	for (auto i : w)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}