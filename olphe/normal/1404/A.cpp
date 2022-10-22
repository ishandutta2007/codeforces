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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		string s;
		cin >> s;
		bool flag = true;
		for (int i = M; i < N; i++) {
			if (s[i] == '?') {
				s[i] = s[i - M];
			}
			if (s[i] != s[i - M] && s[i - M] != '?')flag = false;
		}
		for (int i = N - 1; i >= 0; i--) {
			if (i + M < N) {
				if (s[i] == '?')s[i] = s[i + M];
			}
		}
		int a, b, c;
		a = b = c = 0;
		for (int i = 0; i < M; i++) {
			if (s[i] == '0')a++;
			else if (s[i] == '1')b++;
			else c++;
		}
		if (a + c < M / 2 || b + c < M / 2)flag = false;
		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}
}