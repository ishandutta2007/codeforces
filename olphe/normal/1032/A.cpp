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

//const long long int MOD = 1000000007;
const long long  int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<int>v(101);
	for (int i = 0; i < N; i++) {
		cin >> L;
		v[L]++;
	}
	int box = 0;
	int cnt = 0;
	for (int i = 1; i <= 100; i++) {
		box = max(box, v[i]);
		if (v[i])cnt++;
	}
	box = box / K + !!(box%K);
	cout<<box*K*cnt - N << endl;
	return 0;
}