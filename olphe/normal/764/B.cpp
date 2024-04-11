#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;
const long long int MOD = 1000000007;

int N;
int num[200000];
int ans[200000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < N; i++) {
		if (min(abs(i + 1), abs(N - i)) % 2) {
			ans[N - i - 1] = num[i];
		}
		else {
			ans[i] = num[i];
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}