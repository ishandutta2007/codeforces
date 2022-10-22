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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	map<int, int>m;
	for (int i = 0; i < N; i++) {
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> K;
			m[K]++;
		}
	}
	for (auto i : m) {
		if (i.second == N)cout << i.first << " ";
	}
}