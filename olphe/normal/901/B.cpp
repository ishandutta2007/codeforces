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
#include "iomanip"
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>a(N + 1);
	vector<int>b(N + 1);
	a[0] = -1;
	a[2] = 1;
	b[1] = 1;
	if (N == 1) {
		cout << "1\n0 1\n0\n1\n";
		return 0;
	}
	for (int i = 3; i <= N; i++) {
		bool flag = true;
		for (int j = 1; j <= i; j++) {
			if (i % 2==0) {
				if (abs(a[j] + b[j - 1]) >= 2) {
					flag = false;
				}
			}
			else {
				if (abs(b[j] + a[j - 1]) >= 2) {
					flag = false;
				}
			}
		}
		if (flag) {
			for (int j = 1; j <= i; j++) {
				if (i % 2==0) {
					a[j] += b[j - 1];
				}
				else {
					b[j] += a[j - 1];
				}
			}
		}
		else {
			for (int j = 1; j <= i; j++) {
				if (i % 2==0) {
					a[j] -= b[j - 1];
				}
				else {
					b[j] -= a[j - 1];
				}
			}
		}
	}
	for (int i = 0; i <= N; i++) {
		if (a[i]) {
			L = i;
		}
		if (b[i]) {
			R = i;
		}
	}
	if (R < L) {
		cout << L << endl;
		for (int i = 0; i <= L; i++) {
			cout << a[i] * a[L] << " ";
		}
		cout << endl;
		cout << R << endl;
		for (int i = 0; i <= R; i++) {
			cout << b[i] * b[R] << " ";
		}
	}
	else {
		cout << R << endl;
		for (int i = 0; i <= R; i++) {
			cout << b[i] * b[R] << " ";
		}
		cout << endl;
		cout << L << endl;
		for (int i = 0; i <= L; i++) {
			cout << a[i] * a[L] << " ";
		}
	}
	cout << endl;
	return 0;
}