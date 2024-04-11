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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N + 1);
	vector<int>flag(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		if (R <= N) {
			flag[R] = 1;
		}
		if (L > R)swap(L, R);
		if (L > N || R <= N) {
			cout << -1 << endl;
			return 0;
		}
		v[L] = R;
	}
	vector<int>mx(N + 2, -1);
	for (int i = N; i >= 1; i--) {
		mx[i] = max(mx[i + 1], v[i]);
	}
	vector<int>a;
	vector<int>b;
	int ans = 0;
	int mn = MOD;
	int ca = 0, cb = 0;
	for (int i = 1; i <= N; i++) {
		if (a.empty() || a.back() > v[i]) {
			a.push_back(v[i]);
			ca += flag[i];
		}
		else if (b.empty() || b.back() > v[i]) {
			b.push_back(v[i]);
			cb += flag[i];
		}
		else {
			cout << -1 << endl;
			return 0;
		}
		mn = min(mn, v[i]);
		if (mn > mx[i + 1]) {
			int as = a.size();
			int bs = b.size();
			ans += min(ca + bs - cb, cb + as - ca);
			ca = cb = 0;
			a.clear();
			b.clear();
		}
	}
	cout << ans << endl;
}