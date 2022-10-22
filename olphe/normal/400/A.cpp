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

	cin >> K;
	while (K--) {
		string s;
		cin >> s;
		vector<int>ans;
		for (int i = 12; i >=1; i--) {
			if (12 % i)continue;
			bool flag = false;
			for (int j = 0; j < i; j++) {
				bool box = true;
				for (int k = j; k < 12; k += i) {
					box &= s[k] == 'X';
				}
				flag |= box;
			}
			if (flag)ans.push_back(i);
		}
		cout << ans.size();
		for (auto j : ans)cout << " " << 12 / j << "x" << j;
		cout << endl;
	}
}