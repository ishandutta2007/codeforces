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
		cin >> s[i];
		for (int j = 0; j < W; j++) {
			if (s[i][j] == '*') {
				N ^= i;
				M ^= j;
			}
		}
	}
	cout<<N+1<<" "<<M+1<<endl;
	return 0;
}