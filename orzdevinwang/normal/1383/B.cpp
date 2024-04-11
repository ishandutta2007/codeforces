#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--) 
#define ll long long
#define db double 
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N], cnt[33];
void work() {
	R(i, 30, 0) {
		if(cnt[i] & 1) {
			int gg = n - cnt[i];
			if(cnt[i] % 4 == 1) { 
				printf("WIN\n");
				return;
			}
			else {
				if(gg % 2 == 0) {
					printf("LOSE\n");
					return;
				}
				else {
					printf("WIN\n");
					return;
				}
			}
		}
	}
	printf("DRAW\n");
}
int main() {
	scanf("%d", &T);
	while(T--) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		L(i, 1, n) {
			scanf("%d", &a[i]);
			L(j, 0, 30) if(a[i] & (1 << j)) cnt[j]++;
		}
		work();
	}
	return 0;
}