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

	cin >> N >> K >> H >> W;
	if (N == 1) {
		cout << "0\n";
		return 0;
	}
	M = (N - 1)*K;
	M = min(M, (N - 1)*H);
	M = min(M, (N - 2)*W + min(K, H));
	cout << M << endl;
	return 0;
}