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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string s;
	cin >> s;
	s.push_back('S');
	vector<int>v;
	int cnt = 0;
	for (auto i : s) {
		if (i == 'S') {
			v.push_back(cnt);
			cnt = 0;
		}
		else cnt++;
	}
	if (v.empty()) {
		cout << 0 << endl;
		return 0;
	}
	if (v.size() == 1) {
		cout << v[0] << endl;
		return 0;
	}
	if (v.size() == 2) {
		cout << accumulate(v.begin(), v.end(), 0) << endl;
		return 0;
	}
	int num = 0;
	for (auto i : v)num += !!i;
	if (!num) {
		cout << 0 << endl;
		return 0;
	}
	if (num == 1) {
		for (auto i : v) {
			if (i) {
				cout << i << endl;
				return 0;
			}
		}
	}
	int ans = 0;
	if (num == 2) {
		for (int i = 1; i < v.size(); i++) {
			if (v[i - 1] && v[i]) {
				ans = max(ans, v[i - 1] + v[i]);
			}
			else ans = max(ans, v[i - 1] + v[i] + 1);
		}
	}
	else {
		for (int i = 1; i < v.size(); i++) {
			ans = max(ans, v[i - 1] + v[i] + 1);
		}
	}
	cout << ans << endl;
}