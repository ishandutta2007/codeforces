#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
typedef long double ld;

using namespace std;

const int dd = (int)1e5 + 7;

int A[dd], B[dd];
vector<int> G[dd];
int win[dd];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		B[A[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = B[i] + i; j < n; j += i) {
			if (A[j] > i) {
				G[i].push_back(A[j]);
			}
		}
		for (int j = B[i] - i; j >= 0; j -= i) {
			if (A[j] > i) {
				G[i].push_back(A[j]);
			}
		}
	}
	win[n] = 0;
	for (int i = n - 1; i > 0; --i) {
		int ok = 0;
		for (int j : G[i]) {
			if (!win[j]) {
				ok = 1;
				break;
			}
		}
		win[i] = ok;
	}
	for (int i = 0; i < n; ++i) {
		cout << (win[A[i]] ? "A" : "B"); 
	}
	cout << "\n";
	return 0;
}