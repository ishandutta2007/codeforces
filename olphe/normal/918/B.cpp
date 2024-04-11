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

	cin >> N >> M;
	map<string, string>m;
	for (int i = 0; i < N+M; i++) {
		string s, t;
		cin >> s >> t;
		if (t.back() == ';') {
			t.pop_back();
			cout << s << " " << t << "; #" << m[t] << endl;
		}
		else {
			m[t] = s;
		}
	}
	return 0;
}