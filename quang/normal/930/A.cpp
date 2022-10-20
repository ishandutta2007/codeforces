#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int p[N], lv[N];
int cnt[N];

int main() {
	scanf("%d", &n);
	lv[1] = 1;
	cnt[1] = 1;
	for (int i = 2; i <= n; i++) {
		scanf("%d", p + i);
		lv[i] = lv[p[i]] + 1;
		cnt[lv[i]] ^= 1;	
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += cnt[i];
	}
	cout << res << endl;
	return 0;
}