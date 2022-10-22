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
#include "iomanip"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	cin >> M;
	queue<int>Q;
	for (int i = 1; i < N; i++) {
		cin >> L;
		Q.push(L);
	}
	int box = 0;
	while (1) {
		int bag = Q.front();
		Q.pop();
		if (M > bag) {
			box++;
			Q.push(bag);
		}
		else {
			Q.push(M);
			M = bag;
			box = 1;
		}
		if (box >= K) {
			cout << M << endl;
			return 0;
		}
		if (box >= N) {
			cout << M << endl;
			return 0;
		}
	}
	return 0;
}