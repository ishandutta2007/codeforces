#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int T, n, k, a[N];
char s[N];
int main() {
	scanf("%d", &T);
	while(T--) {
		bool flag = 0;
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		for(int i = 0; i < k; i++) a[i] = -1;
		for(int i = 0; i < n; i++) if(s[i] != '?') {
			if(a[i % k] != -1 && a[i % k] != s[i] - '0') {
				flag = 1;
				printf("NO\n");
				break;
			}
			a[i % k] = s[i] - '0';
		}
		if(flag) continue;
		int cnta = 0, cntb = 0;
		for(int i = 0; i < k; i++) {
			if(a[i] == 0) cnta ++;
			if(a[i] == 1) cntb ++;
		}
		if(cnta > k / 2 || cntb > k / 2) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}