#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int N,K;
long long int num[100000];
long long int m=LLONG_MAX;
long long int ans;

int main() {
	cin >> N>>K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		m = min(m, num[i]);
	}
	for (int i = 0; i < N; i++) {
		if ((num[i] - m) % K) {
			cout << "-1\n";
			return 0;
		}
		ans += (num[i] - m) / K;
	}
	cout << ans << endl;
	return 0;
}