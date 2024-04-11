#include<bits/stdc++.h>
#define N 100010
#define B 98
using namespace std;
int Ans = 1;
bool Prime[N];
int tot, p[N];
void xxs(int x) {
	for(int i = 2; i <= x; i++) { 
		if(!Prime[i]) p[++tot] = i;
		for(int j = 1; p[j] * i <= x && j <= tot; j++) {
			Prime[p[j] * i] = 1;
			if(i % p[j] == 0) break;
		} 
	} 
} 
int n, tt, maxn;
void get(int x) {
	int now = 1;
	printf("B %d\n", x);
	fflush(stdout);
	scanf("%d", &tt);
	while(1) {
		now *= x;
		if(now > n) break;
		printf("A %d\n", now);
		fflush(stdout);
		scanf("%d", &tt);
		if(tt == 0) break;
		Ans *= x;
	}
}
int main() {
	scanf("%d", &n);
	xxs(n);
	for(int i = 1; i <= tot; i++) if(p[i] <= sqrt(n)) maxn = i;
	int ssss = n, L = maxn, R = tot;
	for(int i = 1; i <= B; i++) { 
		int L = (i - 1) * B + 1, R = min(i * B, tot);
		for(int j = L; j <= R; j++) {
			if(j <= maxn) continue;
			printf("B %d\n", p[j]);
			fflush(stdout);
			scanf("%d", &tt);
			ssss -= tt;
		}
		printf("A 1\n");
		fflush(stdout);
		scanf("%d", &tt);
		if(ssss != tt) {
			for(int j = L; j <= R; j++) {
				if(j <= maxn) continue;
				
				printf("A %d\n", p[j]);
				fflush(stdout);
				scanf("%d", &tt);
				
				if(tt) {
					Ans = p[j];
					break;
				}
			}
			break;
		}
		if(R == tot) break;
	}
	
	for(int i = 1; i <= maxn; i++) get(p[i]);
	
	printf("C %d\n", Ans);
	fflush(stdout);
	return 0;
}