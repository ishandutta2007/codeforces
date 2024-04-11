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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<pair<int, int>>v(N);
	for (int i = 0; i < N; i++) {
		pair<int, int>p;
		cin >> p.first >> p.second;
		p.first *= -1;
		v[i] = p;
	}
	M--;
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		K += (v[i] == v[M]);
	}
	cout << K << endl;
	return 0;
}