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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		string s, t;
		cin >> s >> t;
		int step = 0;
		L = 0, R = N - 1;
		vector<int>ans;
		for (int i = N - 1; i >= 0; i--) {
			if (step & 1) {
				if (s[L] != t[i]) {
					L++;
					continue;
				}
				else if (s[R] == t[i]) {
					ans.push_back(i + 1);
					step++;
					R--;
				}
				else {
					ans.push_back(1);
					ans.push_back(i + 1);
					step++;
					R--;
				}
			}
			else {
				if (s[R] == t[i]) {
					R--;
					continue;
				}
				else if (s[L] != t[i]) {
					ans.push_back(i + 1);
					step++;
					L++;
				}
				else {
					step++;
					ans.push_back(1);
					ans.push_back(i + 1);
					L++;
				}
			}
		}
		cout << ans.size();
		for (auto i : ans)cout << " " << i;
		cout << endl;
	}
}