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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t, u;
	cin >> s >> t >> u;
	if (s == t && s == u) {
		cout << "?\n";
		return 0;
	}
	if (s != t && s != u && t != u) {
		cout << "?\n";
		return 0;
	}
	string r;
	r.push_back(s[0]);
	r.push_back(t[0]);
	r.push_back(u[0]);
	sort(r.begin(), r.end());
	if (r == "rrs" || r == "ppr" || r == "pss") {
		cout << "?\n";
		return 0;
	}
	char box = r[0] ^ r[1] ^ r[2];
	
	if (s[0] == box)cout << "F\n";
	if (t[0] == box)cout << "M\n";
	if (u[0] == box)cout << "S\n";

	return 0;
}