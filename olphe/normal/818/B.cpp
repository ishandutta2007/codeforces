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
	cin >> N >> M;
	int num[1000] = {};
	int c;
	cin >> c;
	for (int i = 1; i < M; i++) {
		int a;
		cin >> a;
		if (a <= c) {
			if (num[c] && num[c] != a + N - c) {
				cout << "-1\n";
				return 0;
			}
			num[c] = a + N - c;
		}
		else {
			if (num[c] && num[c] != a - c) {
				cout << "-1\n";
				return 0;
			}
			num[c] = a - c;
		}
		c = a;
	}
	bool flag[1000] = {};
	for (int i = 1; i <= N; i++) {
		if (num[i]&&flag[num[i]]) {
			cout << "-1\n";
			return 0;
		}
		flag[num[i]] = true;
	}
	for (int i = 1; i <= N; i++) {
		if (!num[i]) {
			for (int j = 1; j <= N; j++) {
				if (!flag[j]) {
					num[i] = j;
					flag[j] = true;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (i>1)cout << " ";
		cout << num[i];
	}
	cout << endl;
	return 0;
}