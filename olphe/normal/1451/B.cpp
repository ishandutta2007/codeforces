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
		cin >> N >> K;
		string s;
		cin >> s;
		while (K--) {
			cin >> L >> R;
			L--, R--;
			bool flag = false;
			for (int i = 0; i < L; i++) {
				if (s[i] == s[L])flag = true;
			}
			for (int i = R + 1; i < N; i++) {
				if (s[i] == s[R])flag = true;
			}
			if (flag)cout << "YES\n";
			else cout << "NO\n";
		}
	}
}