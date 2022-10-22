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

	cin >> N;
	vector<int>num(N);
	vector<int>dif(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i] >> dif[i];
		for (int j = num[i];; j += dif[i]) {
			if (M < j) {
				M = j;
				break;
			}
		}
	}
	cout << M << endl;
	return 0;
}