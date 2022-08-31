#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
const int N = 2e5 + 7;
int T, n, m;
int p[N], cnt, tt[N], tot, lb[N], lbs;
int main() {
	scanf("%d", &T);
	while(T--) {
		cnt = tot = lbs = 0;
		scanf("%d", &n);
		for(int i = 2; i <= sqrt(n); i++) 
			if(n % i == 0) {
				p[++cnt] = i;
				if(i != n / i) p[++cnt] = n / i;
			}
		p[++cnt] = n;
		sort(p + 1, p + cnt + 1);
		for(int i = 1; i <= cnt; i++) {
			bool flag = 1;
			for(int j = 1; j <= cnt; j++) 
				if(j != i && p[i] % p[j] == 0) {
					flag = 0;
					break;
				}
			if(flag) lb[++lbs] = p[i];
		}
		if(cnt == 3 && p[2] % p[1] != 0) printf("%d %d %d\n1\n", p[1], p[2], p[3]);
		else {
			for(int g = 1; g <= lbs; g++) {
				int las = tot;
				for(int i = 1; i <= cnt; i++) 
					if(p[i] % lb[g] == 0 && p[i] != 0) 
						tt[++tot] = p[i], p[i] = 0;
				if(g == 1) {
					for(int i = las + 1; i <= tot; i++) 
						if(tt[i] % lb[lbs] == 0) {
							swap(tt[i], tt[las + 1]);
							break;
						}
					las ++;
				}
				for(int i = las + 1; i <= tot; i++) 
					if(tt[i] % lb[g % lbs + 1] == 0) {
						swap(tt[i], tt[tot]);
						break;
					}
			}
			for(int i = 1; i <= tot; i++) printf("%d ", tt[i]);
			printf("\n0\n");
		}
	} 
	return 0;
}