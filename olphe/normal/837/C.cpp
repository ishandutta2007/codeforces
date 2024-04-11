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

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H, L, R;
long long int ans;



int main() {
	ios::sync_with_stdio(false);
	cin >> N >> H >> W;
	int x[100];
	int y[100];
	if (H > W)swap(H, W);
	for (int i = 0; i < N; i++)cin >> x[i] >> y[i];
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			L = x[i] + x[j];
			R = max(y[i], y[j]);
			if (L > R)swap(L, R);
			if (L <= H&&R <= W)ans = max((int)ans, x[i] * y[i] + x[j] * y[j]);
			L = y[i] + y[j];
			R = max(x[i], x[j]);
			if (L > R)swap(L, R);
			if (L <= H&&R <= W)ans = max((int)ans, x[i] * y[i] + x[j] * y[j]);
			L = x[i] + y[j];
			R = max(y[i], x[j]);
			if (L > R)swap(L, R);
			if (L <= H&&R <= W)ans = max((int)ans, x[i] * y[i] + x[j] * y[j]);
			L = y[i] + x[j];
			R = max(x[i], y[j]);
			if (L > R)swap(L, R);
			if (L <= H&&R <= W)ans = max((int)ans, x[i] * y[i] + x[j] * y[j]);
		}
	}
	cout << ans << endl;
	return 0;
}