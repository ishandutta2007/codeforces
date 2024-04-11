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
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	long long int bef = 0;
	long long int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> K;
		sum += K;
		cout << sum / M - bef << " ";
		bef = sum / M;
	}
	cout << endl;
	return 0;
}