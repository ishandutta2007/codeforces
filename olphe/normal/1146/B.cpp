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

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	N = s.size();
	for (auto i : s)M += i != 'a';
	if (M & 1) {
		cout << ":(\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		K += s[i] != 'a';
		if (K > M / 2 || i == N - 1) {
			string t;
			for (int j = 0; j < i+(!M); j++) {
				t.push_back(s[j]);
			}
			string u = t;
			string w = t;
			for (auto j : u) {
				if (j != 'a')t.push_back(j);
			}
			if (t == s) {
				cout << w << endl;
				return 0;
			}
			else {
				cout << ":(\n";
				return 0;
			}
		}
	}
	return 0;
}