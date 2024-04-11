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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	string t, u, v;
	string ot, ou, ov;
	for (int i = 0; i < s.size(); i++) {
		int a, b, c;
		a = i % 26;
		b = (i / 26) % 26;
		c = (i / 26 / 26) % 26;
		ot.push_back('a' + a);
		ou.push_back('a' + b);
		ov.push_back('a' + c);
	}
	cout << "? " << ot << endl;
	cin >> t;
	cout << "? " << ou << endl;
	cin >> u;
	cout << "? " << ov << endl;
	cin >> v;
	vector<int>x(s.size());
	for (int i = 0; i < s.size(); i++) {
		x[i] = (v[i] - 'a') * 26 * 26 + (u[i] - 'a') * 26 + t[i] - 'a';
	}
	string ans(s.size(), 'a');
	for (int i = 0; i < s.size(); i++) {
		ans[x[i]] = s[i];
	}
	cout << "! " << ans << endl;
	return 0;
}