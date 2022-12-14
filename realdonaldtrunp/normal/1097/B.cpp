#include"bits/stdc++.h"
using namespace std;

int n;
vector<int> a;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		a.push_back(c);
	}
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				cnt += a[j];
				cnt %= 360;
			}
			else {
				cnt += 360;
				cnt -= a[j];
				cnt %= 360;
			}
		}
		if (cnt == 0) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}