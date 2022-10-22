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
	long long int num = 0;
	vector<long long int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> M;
		num += M;
	}
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	if (v[0] + v[1] >= num) {
		cout << "yes\n";
	}
	else {
		cout << "no\n";
	}
	return 0;
}