/* D. Maximum Submatrix 2 */

#include <stdio.h>

#define MX_N 5010

char str[MX_N][MX_N];
int cnt[MX_N][MX_N];
int n,m;

int main() {
	int i,j;
	scanf("%d %d",&n,&m);
	int a,b;
	for(i=0;i<n;i++) {
		scanf("%s",str[i]);
		for(a=b=0;b<m;a = ++b) {
			while(b < m && (str[i][b+1] == '1' || str[i][b] == '0'))
				b++;
			while(a < m && str[i][a] == '0') 
				a++;
			if(a < m && b < m && a <= b)
				cnt[a][b]++;
		}
	}
	for(i=0;i<m;i++) {
		for(j=m-1;j>=i;j--) {
			if(i > 0) cnt[i][j] += cnt[i-1][j];
			if(j+1 < m) cnt[i][j] += cnt[i][j+1];
			if(i > 0 && j+1 < m) cnt[i][j] -= cnt[i-1][j+1];
		}
	}
	int ans = 0;
	for(a=0;a<m;a++) {
		for(b=a;b<m;b++) {
			int k = (b-a+1) * (cnt[a][b]);
			if(k > ans) {
				ans = k;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}