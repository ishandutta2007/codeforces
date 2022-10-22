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
	cin >> N >> M;
	string s;
	cin >> s;
	for (auto& i : s)i -= '0';
	int rev[] = { 0,1,5,-1,-1,2,-1,-1,8,-1 };
	int a, b, c, d;
	a = s[0];
	b = s[1];
	c = s[3];
	d = s[4];
	int h = a * 10 + b;
	int m = c * 10 + d;
	while (1) {
		if (rev[h % 10] != -1 && rev[h / 10] != -1 && rev[m % 10] != -1 && rev[m / 10] != -1) {
			int nh = rev[m % 10] * 10 + rev[m / 10];
			int nm = rev[h % 10] * 10 + rev[h / 10];
			if (nh < N && nm < M) {
				cout << h / 10 << h % 10 << ":" << m / 10 << m % 10 << endl;
				return;
			}
		}
		m++;
		if (m >= M) {
			m = 0;
			h++;
		}
		if (h >= N) {
			h = 0;
		}
	}
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