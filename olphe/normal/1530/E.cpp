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

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	string s;
	cin >> s;
	int num[256] = {};
	for (auto i : s) {
		num[i]++;
	}
	int one = 0;
	int same = 0;
	for (int i = 'z'; i >= 'a'; i--) {
		if (num[i] == 1) {
			one = i;
		}
		if (num[i] == s.size()) {
			same = 1;
		}
	}
	if (same) {
		cout << s << endl;
		return;
	}
	if (one) {
		string ans(1, one);
		for (int i = 'a'; i <= 'z'; i++) {
			if (i != one) {
				for (int j = 0; j < num[i]; j++) {
					ans.push_back(i);
				}
			}
		}
		cout << ans << endl;
		return;
	}
	string ans;
	for (int i = 'a'; i <= 'z'; i++) {
		if (num[i]) {
			if (num[i] * 2 - 2 <= s.size()) {
				ans.push_back(i);
				ans.push_back(i);
				num[i] -= 2;
				for (int j = i + 1; j <= 'z'; j++) {
					for (int k = 0; k < num[j]; k++) {
						ans.push_back(j);
						if (num[i]) {
							num[i]--;
							ans.push_back(i);
						}
					}
				}
				cout << ans << endl;
				return;
			}
			break;
		}
	}
	for (int i = 'a'; i <= 'z'; i++) {
		if (!num[i])continue;
		for (int j = i + 1; j <= 'z'; j++) {
			if (!num[j])continue;
			ans.push_back(i);
			ans.push_back(j);
			num[i]--;
			num[j]--;
			for (int k = j + 1; k <= 'z'; k++) {
				if (num[k]) {
					for (int l = 0; l < num[i]; l++)ans.push_back(i);
					num[k]--;
					ans.push_back(k);
					for (int l = 0; l < num[j]; l++)ans.push_back(j);
					for (int l = k; l <= 'z'; l++) {
						for (int m = 0; m < num[l]; m++)ans.push_back(l);
					}
					cout << ans << endl;
					return;
				}
			}
			for (int k = 0; k < num[j]; k++) {
				ans.push_back(j);
			}
			for (int k = 0; k < num[i]; k++) {
				ans.push_back(i);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}