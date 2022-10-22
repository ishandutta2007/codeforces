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

	string s;
	cin >> s;
	vector<string>t;
	string u;
	for (int i = 0; i < s.size(); i++) {
		if (i + 2 < s.size()) {
			if (s[i + 0] == 'W'&&s[i + 1] == 'U'&&s[i + 2] == 'B') {
				if (!u.empty()) {
					t.push_back(u);
					u.clear();
				}
				i += 2;
			}
			else {
				u.push_back(s[i]);
			}
		}
		else {
			u.push_back(s[i]);
		}
	}
	if (!u.empty())t.push_back(u);

	for (auto i : t)cout << i << " ";
	cout << endl;
}