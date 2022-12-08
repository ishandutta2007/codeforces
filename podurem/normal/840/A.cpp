#include <bits/stdc++.h>

using namespace std;

const int dd = (int)2e5 + 1;
const int INF = (int)1e9 + 7;

pair<int, int> B[dd];
int ans[dd], A[dd];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	for (int i = 0; i < n; ++i)
		cin >> B[i].first, B[i].second = i;
	sort(A, A + n);
	sort(B, B + n);
	for (int i = 0; i < n; ++i)
		ans[B[i].second] = A[n - i - 1];
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
    return 0;
}