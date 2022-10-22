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

long long int N, M, K, Q, W, H;
long long int ans;


int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	int num[500][500] = {};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)cin >> num[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (num[i][j] == 1)continue;
			bool flag = false;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					if (num[i][j] == num[i][k] + num[l][j]) {
						flag = true;
						break;
					}
				}
			}
			if (flag)continue;
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}