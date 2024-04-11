#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

long long ans = 0x3f3f3f3f3f3f3f3f;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1;; i++) {
		long long sum = 1, flag = 0;
		for (int j = 1; j < n; j++) {
			sum *= i;
			if (sum > 1e10) {flag = 1; break;}
		}
		if (flag) break;
		sum = 0; long long cnt = 1;
		for (int j = 1; j <= n; j++) {
			if (j != 1) cnt *= i;
			sum += abs(cnt - a[j]);
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}