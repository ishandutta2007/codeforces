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
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	sort(v.begin(), v.end());
	if (v[N - 3] + v[N - 2] <= v[N - 1]) {
		cout << "NO\n";
		return 0;
	}
	list<int>ans;
	for (int i = 0; i < N; i++) {
		if (i & 1)ans.push_back(v[i]);
		else ans.push_front(v[i]);
	}
	cout << "YES\n";
	for (auto i : ans)cout << i << " ";
	cout << endl;
}