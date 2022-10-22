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

	cin >> N >> M >> K;
	vector<int>sum(K);
	vector<int>num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		sum[num[i] % K]++;
	}
	for (int i = 0; i < K; i++) {
		if (sum[i] >= M) {
			cout << "Yes\n";
			int box = 0;
			for (int j = 0; j < N; j++) {
				if (num[j] % K == i) {
					cout << num[j] << " ";
					box++;
				}
				if (box == M) {
					cout << endl;
					return 0;
				}
			}
		}
	}
	cout << "No\n";
	return 0;
}