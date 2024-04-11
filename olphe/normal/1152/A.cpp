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
//const int MOD = 1000000007;
const int MOD = 998244353;
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int o = 0, e = 0;
	for (int i = 0; i < N; i++) {
		cin >> K;
		if (K & 1)o++;
		else e++;
	}
	int oo = 0, ee = 0;
	for (int i = 0; i < M; i++) {
		cin >> K;
		if (K & 1)oo++;
		else ee++;
	}
	cout << min(o, ee) + min(e, oo) << endl;
	return 0;
}