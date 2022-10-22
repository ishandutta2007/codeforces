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

	cin >> N;
	string s;
	cin >> s;
	s.push_back('_');
	vector<string>o;
	int ans = 0;
	string t;
	bool flag = false;
	for (auto i : s) {
		if (i == '(') {
			if (ans < t.size()) {
				ans = t.size();
			}
			t.clear();
			flag = true;
		}
		else if (i == ')') {
			if (!t.empty()) {
				o.push_back(t);
				t.clear();
			}
			flag = false;
		}
		else if (i != '_') {
			t.push_back(i);
		}
		else{
			if (flag) {
				if (!t.empty()) {
					o.push_back(t);
					t.clear();
				}
			}
			else {
				if (!t.empty()) {
					if (ans < t.size()) {
						ans = t.size();
					}
					t.clear();
				}
			}
		}
	}
	cout << ans << " " << o.size() << endl;
}