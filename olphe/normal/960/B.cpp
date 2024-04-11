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

	cin >> N >> M >> K;
	vector<long long int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	priority_queue<long long int>PQ;
	for (int i = 0; i < N; i++) {
		cin >> L;
		PQ.push(abs(v[i] - L));
	}
	M += K;
	while (M) {
		M--;
		int cn = PQ.top();
		PQ.pop();
		cn = abs(cn - 1);
		PQ.push(cn);
	}
	long long ans = 0;
	while (!PQ.empty()) {
		long long int cn = PQ.top();
		ans += cn*cn;
		PQ.pop();
	}
	cout << ans << endl;
	return 0;
}