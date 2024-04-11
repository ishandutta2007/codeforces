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
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	N *= 2;
	int num[200] = {};
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	M = INT_MAX;
	sort(num, num + N);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int box = 0;
			int sum = 0;
			for (int k = 0; k < N; k++) {
				if (k == i || k == j)continue;
				if (box) {
					sum += abs(box - num[k]);
					box = 0;
				}
				else {
					box = num[k];
				}
			}
			M = min((int)M, sum);
		}
	}
	cout << M << endl;
	return 0;
}