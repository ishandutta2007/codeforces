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
	for (int i = 0; i < N; i++) {
		cin >> M;
		if (M < 4) {
			cout << -1 << endl;
		}
		else if (M % 2 == 0) {
			cout << M / 4 << endl;
		}
		else  {
			M -= 9;
			if (M < 4&&M) {
				cout << -1 << endl;
			}
			else {
				cout << 1 + M / 4 << endl;
			}
		}
	}
	return 0;
}