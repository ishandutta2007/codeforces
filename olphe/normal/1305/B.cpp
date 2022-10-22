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
constexpr long  double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int>a;
	vector<int>b;
	int cnt = 0;
	for (auto i : s) {
		if (i == '(')a.push_back(cnt++);
		if (i == ')')b.push_back(cnt++);
	}
	reverse(a.begin(), a.end());
	vector<int>l;
	vector<int>r;
	while (a.size() && b.size() && a.back() < b.back()) {
		l.push_back(a.back());
		r.push_back(b.back());
		a.pop_back();
		b.pop_back();
	}
	if (l.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << 1 << endl;
	cout << l.size() * 2 << endl;
	reverse(r.begin(), r.end());
	for (auto i : l)cout << i+1 << " ";
	for (auto i : r)cout << i+1 << " ";
	cout << endl;
}