#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[100], ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i <<= 1) {
		for (int j = 0; j < n; j += i) {
			bool is = 1;
			for (int k = j + 1; k < j + i; ++k)
				if (a[k - 1] > a[k]) is = 0;
			if (is) ans = i;
		}
	}
	printf("%d", ans);
}