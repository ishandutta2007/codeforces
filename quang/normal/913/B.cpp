#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int p[N];
int hasChild[N], num[N];

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", p + i);
	}
	int f = 0;
	for (int i = n; i; i--) {
		if (!hasChild[i]) {
			num[p[i]]++;
		} else {
			if (num[i] < 3) {
				f = 1;
				break;
			}
		}
		hasChild[p[i]] = 1;
	}
	puts(f ? "No" : "Yes");
	return 0;
}