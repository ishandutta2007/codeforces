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
		string s;
		cin >> s;
		vector<int>ans(N);
		set<int>zero;
		set<int>one;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			if (s[i] == '0') {
				if (one.empty()) {
					zero.insert(cnt);
					ans[i] = cnt;
					cnt++;
				}
				else {
					zero.insert(*one.begin());
					ans[i] = *one.begin();
					one.erase(one.begin());
				}
			}
			else {
				if (zero.empty()) {
					one.insert(cnt);
					ans[i] = cnt;
					cnt++;
				}
				else {
					one.insert(*zero.begin());
					ans[i] = *zero.begin();
					zero.erase(zero.begin());
				}
			}
		}
		cout << cnt - 1 << endl;
		for (auto i : ans)cout << i << " ";
		cout << endl;
	}
}