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

long long int N, M, K, W, H, L, R;
long long int ans;



int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	int num[2900];
	for (int i = 0; i < N*2; i++) {
		cin >> num[i];
	}
	sort(num, num + N * 2);
	if (num[N] == num[N-1]) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
	return 0;
}