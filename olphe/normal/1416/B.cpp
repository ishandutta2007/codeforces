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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<int>v(N + 1);
		for (int i = 1; i <= N; i++)cin >> v[i];
		vector<int>a;
		vector<int>b;
		vector<int>c;
		M = accumulate(v.begin(), v.end(), 0LL);
		if (M%N) {
			cout << -1 << endl;
			continue;
		}
		M /= N;
		for (int i = 2; i <= N; i++) {
			if (v[i] % i) {
				int num = i - v[i] % i;
				a.push_back(1);
				b.push_back(i);
				c.push_back(num);
				v[i] += num;
				v[1] -= num;
			}
			a.push_back(i);
			b.push_back(1);
			c.push_back(v[i] / i);
			v[1] += v[i];
			v[i] = 0;
		}
		for (int i = 2; i <= N; i++) {
			a.push_back(1);
			b.push_back(i);
			int num = M - v[i];
			c.push_back(num);
			v[i] += num;
			v[1] -= num;

		}
		cout << a.size() << endl;
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " " << b[i] << " " << c[i] << endl;
		}
	}
}