#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 9;
int T, n, m, a[N], cnt;
int main() {
	scanf("%d", &T);
	while(T--) {
		cnt = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt += a[i];
		if(cnt <= n / 2) {
			printf("%d\n", n - cnt);
			for(int i = 1; i <= n - cnt; i++) printf("0 ");
			puts("");
		}
		else {
			printf("%d\n", (cnt / 2) * 2);
			for(int i = 1; i <= (cnt / 2) * 2; i++) printf("1 ");
			puts("");
		}
	}
	return 0;
}