#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 1e6 + 7;
int T, n, tot, a[N], f[N], g[N], nm, cnm, maxn;
int main() {
	scanf("%d", &n), maxn = n;
	tot = 0;
	int sum = 0;
	bool flag = 0, flagb = 0, nflag = 0;
	L(i, 1, n) scanf("%d", &a[i]);
	R(i, n, 1) {
		if(a[i] == 1) nm = 1, ++tot, sum++;
		else if(a[i] == 2) {
			if(tot == 0) {
				flag = 1;
				break;
			}
			if(!flagb) flagb = 1;
			--tot, sum ++;
		}
		else if(a[i] == 3) {
			if(!nflag) {
				nflag = 1;
				if(!nm) {
					flag = 1;
					break;
				}
				else if(!flagb) {
					if(tot == 0) {
						flag = 1;
						break;
					}
					else --tot;
				}
			}
			sum += 2;
		}
	}
	if(flag == 1) {
		printf("-1\n");
		return 0;
	} 
	printf("%d\n", sum);
	nm = cnm = 0;
	tot = 0;
	R(i, n, 1) {
		if(a[i] == 1) {
			printf("%d %d\n", maxn, i);
			if(!nm) nm = i, cnm = maxn;
			else f[++tot] = i, g[tot] = maxn;
			--maxn;
		}
		else {
			if(a[i] > 1) {
				if(a[i] == 2) {
					if(a[nm] == 1) printf("%d %d\n", cnm, i), nm = i;
					else printf("%d %d\n", g[tot], i), --tot;
				}
				else {
					printf("%d %d\n", maxn, nm);
					printf("%d %d\n", maxn, i);
					nm = i;
					--maxn;
				}
			}
		}
	}
	return 0;
}