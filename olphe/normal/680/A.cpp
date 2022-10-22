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

	map<int, int>m;
	for (int i = 0; i < 5; i++) {
		cin >> M;
		m[M]++;
	}
	int box = 0;
	int sum = 0;
	for (auto i : m) {
		if (i.second == 2)box = max(box, i.first * 2);
		if (i.second >= 3)box = max(box, i.first * 3);
		sum += i.first*i.second;
	}
	cout << sum - box << endl;
	return 0;
}