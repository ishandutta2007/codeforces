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

	cin >> N;
	list<int>l;
	l.push_back(1);
	for (int i = 1; i < N; i++) {
		K = 1;
		while (!l.empty()&&K == l.back()) {
			l.pop_back();
			K++;
		}
		l.push_back(K);
	}
	for (auto i : l)cout << i << " ";
	cout << endl;
	return 0;
}