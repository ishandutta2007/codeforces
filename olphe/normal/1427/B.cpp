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
		vector<int>v;
		int num = 0;
		int bef = -1;
		int add = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'W') {
				if (bef != -1) {
					add += i - bef - 1;
					v.push_back(i - bef - 1);
				}
				num++;
				bef = i;
			}
		}
		add += s.size() - bef - 1;
		sort(v.begin(), v.end());
		num = min(N, num + M);
		int ans = max(0,num * 2 - 1);
		for (auto &i : v) {
			if (i <= M) {
				M -= i;
				i = 0;
			}
			else {
				M = 0;
			}
		}
		for (auto i : v)ans -= !!i;
		cout << ans << endl;
	}
}