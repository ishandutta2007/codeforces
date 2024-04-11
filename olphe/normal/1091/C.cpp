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
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	set<long long int>s;
	s.insert(N*(N + 1) / 2);
	for (int i = 2; i * i <= N; i++){
		if (N%i)continue;
		long long int box = N / i;
		s.insert(box*(box - 1) / 2 * i + box);
		box = i;
		s.insert(box*(box - 1) / 2 * (N / i) + box);
	}
	s.insert(1);
	for (auto i : s)cout << i << " ";
	cout << endl;
	return 0;
}