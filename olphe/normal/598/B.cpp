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

const long long  int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> L >> R >> M;
		L--;
		R--;
		M %= (R - L + 1);
		string t = s;
		for (int j = L; j <= R; j++) {
			int nx = j + M;
			if (nx > R)nx -= (R - L + 1);
		//	cout << nx << endl;
			s[nx] = t[j];
		}
	//	cout << s << endl;
	}
	cout << s << endl;
	return 0;
}