#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;

using namespace std;

const int dd = (int)2e5 + 7;

ll A[dd], B[dd];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> B[i];
	}
	int x = max_element(B, B + n) - B;
	for (int i = 0; i < n; ++i) if (B[i] == B[x] && B[i == 0 ? n - 1 : i - 1] != B[x]) {
		x = i;
		break;
	}
	A[x] = B[x] + (B[x] == 0);
	int g = 1;
	for (int i = (x == 0 ? n - 1 : x - 1); i != x; i = (i == 0 ? n - 1 : i - 1)) {
		int j = (i == n - 1 ? 0 : i + 1);
		if (B[i] == 0 && g && B[x] != 0)
			A[i] = A[j] * 2, g = 0;
		else
			A[i] = A[j] + B[i];
	}

	bool f = true;
	for (int i = 0; i < n; ++i) if (A[i] % A[(i + 1) % n] != B[i]) {
		f = false;
	}

	if (!f) {
		return cout << "NO\n", 0;
	}

	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << A[i] << " ";
	}
	cout << "\n";
	return 0;
}