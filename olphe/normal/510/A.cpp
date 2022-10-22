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

	cin >> H >> W;
	vector<string>s(H);
	for (int i = 0; i < H; i++) {
		if(i%2==0)s[i].resize(W, '#');
		else s[i].resize(W, '.');
		if (i % 4 == 1)s[i][W - 1] = '#';
		if (i % 4 == 3)s[i][0] = '#';
	}
	for (auto i : s)cout << i << endl;
	return 0;
}