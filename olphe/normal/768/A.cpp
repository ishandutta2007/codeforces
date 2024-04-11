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
#include "map"

using namespace std;
const long long int MOD = 1000000007;

int N;
int num[100000];
int a, b;
int ans;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	a = num[0];
	b = num[N - 1];
	for (int i = 0; i < N; i++) {
		if (num[i] != a&&num[i] != b)ans++;
	}
	cout << ans << endl;
	return 0;
}