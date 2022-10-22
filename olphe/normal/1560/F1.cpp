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

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void func(string& s, string& t, vector<int>& used,int amari) {
	if (s.size() == t.size())return;
	int num = t.size();
	for (int i = !num; i < 10; i++) {
		if (!used[i] && !amari)continue;
		t.push_back('0' + i);
		auto u = t;
		used[i]++;
		if (used[i] == 1) {
			amari--;
		}
		if (amari) {
			while (u.size() < s.size())u.push_back('9');
		}
		else {
			for (int j = 9; j >= 0; j--) {
				if (used[j]) {
					while (u.size() < s.size())u.push_back('0' + j);
				}
			}
		}
		if (u >= s) {
			func(s, t, used, amari);
			break;
		}
		t.pop_back();
		used[i]--;
		if (used[i] == 0) {
			amari++;
		}
	}
}

void Solve() {
	string s;
	cin >> s >> K;
	string t;
	vector<int>used(10);
	func(s, t, used, K);
	cout << t << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}