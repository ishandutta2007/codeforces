#include<bits/stdc++.h>
#define N 310000
using namespace std;
int T, n, s[N], Ans, now;
char ps[N];
signed main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%s", ps+1), n = strlen(ps+1);
		for(int i = 1; i <= n; i++) s[i] = ps[i] - '0';
		Ans = 0;
		for(int i = 0; i <= 9; i++) {
			for(int j = 0; j <= 9; j++) {
				now = 0;
				for(int k = 1; k <= n; k++) {
					if(now % 2 == 0 && s[k] == i) now++;
					else if(now % 2 == 1 && s[k] == j) now++;
				}
				if(i == j) Ans = max(Ans, now);
				else Ans = max(Ans, (now / 2) * 2);
			}
		}
		printf("%d\n", n - Ans);
	}
    return 0;
}