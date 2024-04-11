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

int N;
long long int num[300000];
long long int box[300000];
long long int p;
long long int m;

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> num[i];
	stable_sort(num, num + N);
	box[0] = 0;
	box[1] = 1;
	for (int i = 2; i < 300000; i++) {
		box[i] = box[i - 1] * 2 + 1;
		box[i] %= MOD;
	}
	for (int i = 0; i < N; i++) {
		m += box[N - 1 - i] * num[i];
		m %= MOD;
		p += box[i] * num[i];
		p %= MOD;
	}
	if (p >= m)cout << p - m << endl;
	else cout << p + MOD - m << endl;
	return 0;
}