#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--) 
#define ll long long
#define db double 
using namespace std;
const int N = 1e5 + 5;
const int cN = 20;
int T, n, a[N], b[N], m, ans, flag;
bool cnt[22][22];
char sa[N], sb[N];
int main() {
	scanf("%d", &T);
	while(T--) {
		memset(cnt, 0, sizeof(cnt));
		flag = 0, ans = 0;
		scanf("%d%s%s", &n, sa, sb);
		memset(cnt, 0, sizeof(cnt));
		L(i, 0, n - 1) {
			a[i] = sa[i] - 'a', b[i] = sb[i] - 'a', flag |= (a[i] > b[i]);
			if(a[i] != b[i])cnt[a[i]][b[i]] = 1;
		}
		if(flag == 1) {
			printf("-1\n");
			continue;
		}
		L(i, 0, cN) 
			L(j, i + 1, cN) 
				if(cnt[i][j]) {
					L(k, j + 1, cN) cnt[j][k] |= cnt[i][k];
					ans ++;
					break;
				} 
		printf("%d\n", ans);
	}
	return 0;
}