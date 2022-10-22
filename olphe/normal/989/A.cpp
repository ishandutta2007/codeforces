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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R, V, E;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	for (int i = 1; i < s.size() - 1; i++) {
		set<char>st;
		for (int j = -1; j <= 1; j++) {
			if (s[i + j] == '.')continue;
			st.insert(s[i + j]);
		}
		if (st.size() == 3) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}