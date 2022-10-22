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
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N + 2);
	vector<int>sum(N + 2);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		sum[max(i - v[i], 1)]++;
		sum[i]--;
	}
	for (int i = 1; i <= N; i++) {
		sum[i] += sum[i - 1];
		if (!sum[i]) {
			M++;
		}
	}
	cout << M << endl;
	return 0;
}