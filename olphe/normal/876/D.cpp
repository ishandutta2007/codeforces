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
	vector<int>num(N);
	vector<bool>flag(N, true);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		num[i]--;
	}
	cout << "1 ";
	M = N - 1;
	K = 1;
	for (int i = 0; i < N-1; i++) {
		flag[num[i]] = false;
		if (num[i] != M) {
			K++;
		}
		else {
			for (int j = M; j >= 0; j--) {
				if (flag[j]) {
					K++;
					K -= (M - j);
					M = j;
					break;
				}
			}
		}
		cout << K << " ";
	}
	cout << "1\n";
	return 0;
}