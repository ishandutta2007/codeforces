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
		string s;
		cin >> s;
		vector<int>box;
		int num = 0;
		for (auto i : s) {
			if (i == '1')num++;
			else {
				if (num > 0) {
					box.push_back(num);
					num = 0;
				}
			}
		}
		if (num > 0)box.push_back(num);
		sort(box.rbegin(), box.rend());
		int ans = 0;
		for (int i = 0; i < box.size(); i += 2)ans += box[i];
		cout << ans << endl;
	}
}