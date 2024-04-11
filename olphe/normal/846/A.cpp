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

long long int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int num[200] = {};
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		sum += num[i];
	}
	int ans = 0;
	for (int i = 0; i <= sum; i++) {
		int box = 0;
		int bag = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (box == i) {
				ans = max(ans, (int)N - bag - sum + i);
				break;
			}
			if (num[j]) {
				box++;
			}
			else {
				bag++;
			}
			if (box == i) {
				ans = max(ans, (int)N - bag - sum + i);
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;

}