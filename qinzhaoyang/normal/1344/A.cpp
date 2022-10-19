#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, T, a[N];

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int flag = 1; map <int,int> mp;
		for (int i = 0; i < n; i++) {	
			int x = -i, m = ((x % n) + n) % n;
//			if (x + a[m] > 0) flag = 0;
			if (mp[((x + a[m]) % n + n) % n]) flag = 0;
			mp[((x + a[m]) % n + n) % n] = 1;
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}