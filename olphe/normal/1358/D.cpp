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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<long long int>v(N);
	for (auto &i : v) {
		cin >> i;
	}
	if (*max_element(v.begin(), v.end())>=M) {
		auto box = *max_element(v.begin(), v.end());
		long long int ans = 0;
		for (int j = box; j > box - M; j--) {
			ans += j;
		}
		cout << ans << endl;
		return 0;
	}
	long long int ans = 0;
	long long int sum = 0;
	long long int a = N, b = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (sum + v[i] <= M) {
			ans += v[i] * (v[i] + 1) / 2;
			sum += v[i];
			a = i, b = 1;
		}
		else {
			for (int j = v[i]; j > 0; j--) {
				ans += j;
				sum++;
				a = i, b = j;
				if (sum == M)break;
			}
		}
		if (sum == M)break;
	}
	sum = ans;
	for (int i = N - 1; i > 0; i--) {
		sum -= v[i] * (v[i] + 1) / 2;
		int amari = v[i];
		while (amari) {
			if (amari < b - 1) {
				sum += (b - 1)*(b) / 2;
				b -= amari;
				sum -= (b - 1)*(b) / 2;
				amari = 0;
			}
			else {
				sum += (b - 1)*(b) / 2;
				amari -= b-1;
				a--;
				if (a < 0)a += N;
				b = v[a] + 1;
			}
		}
		ans = max(ans, sum);
	//	cout << i << " " << sum << endl;
	}
	cout << ans << endl;
}