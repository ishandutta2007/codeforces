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
		string s, t;
		cin >> s >> t;
		vector<int>bef(27);
		vector<int>aft(27);
		for (auto i : s)bef[i - 'a']++;
		for (auto i : t)aft[i - 'a']++;
		bool flag = true;
		for (int i = 0; i < 26; i++) {
			if (bef[i] < aft[i])flag = false;
			if (bef[i] > aft[i]) {
				if ((bef[i] - aft[i]) % K) {
					flag = false;
				}
				else {
					bef[i + 1] += bef[i] - aft[i];
				}
			}
		}
		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}
}