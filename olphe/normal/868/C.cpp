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

	cin >> N >> K;
	int two[] = { 1,2,4,8,16 };
	vector<bool>flag(two[K]);
	for (int i = 0; i < N; i++) {
		int num = 0;
		for (int j = 0; j < K; j++) {
			cin >> M;
			num += M*two[j];
		}
		flag[num] = true;
	}
	if (flag[0]) {
		cout << "YES\n";
		return 0;
	}
	for (int i = 1; i < two[K]; i++) {
		for (int j = i + 1; j < two[K]; j++) {
			if (i % 2 && j % 2) {
				continue;
			}
			if (i % 4 >= 2 && j % 4 >= 2) {
				continue;
			}
			if (i % 8 >= 4 && j % 8 >= 4) {
				continue;
			}
			if (i % 16 >= 8 && j % 16 >= 8) {
				continue;
			}
			if (flag[i] && flag[j]) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}