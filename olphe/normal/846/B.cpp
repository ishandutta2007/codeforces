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

	cin >> N >> M >> K;
	long long int num[50] = {};
	long long int sum = 0;
	for (int i = 0; i < M; i++) {
		cin >> num[i];
		sum += num[i];
	}
	sort(num, num + M);
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		long long int box = 0;
		long long int cost = 0;
		if (sum*i <= K) {
			box = (M + 1)*i;
			cost = sum*i;
		}
		else {
			break;
		}
		for (int j = 0; j < M; j++) {
			if (cost + (N - i)*num[j] <= K) {
				cost += (N - i)*num[j];
				box += N - i;
				if (j == M - 1) {
					box += N - i;
				}
			}
			else if (cost < K) {
				cost = K - cost;
				box += cost / num[j];
				if (j == M - 1) {
					box += cost / num[j];
				}
				break;
			}
			else {
				break;
			}
		}
		ans = max(ans, box);
	}
	cout << ans << endl;
	return 0;

}