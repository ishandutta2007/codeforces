/* B. Vasya and Public Transport */

#include <stdio.h>

#define MX_N 1010

int arr[MX_N][MX_N];
int a[MX_N],b[MX_N];
int c1,c2,c3,c4;
int n,m;

int main() {
	int i;
	scanf("%d %d %d %d %d %d",&c1,&c2,&c3,&c4,&n,&m);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++) {
		scanf("%d",&b[i]);
	}
	int ans = c4;
	int cnt1 = 0,cnt2 = 0;
	for(i=0;i<n;i++) {
		if(a[i] * c1 < c2) {
			cnt1 += a[i] * c1;
		}else {
			cnt1 += c2;
		}
	}
	for(i=0;i<m;i++) {
		if(b[i] * c1 < c2) {
			cnt2 += b[i] * c1;
		}else {
			cnt2 += c2;
		}
	}
	if(cnt1 > c3) cnt1 = c3;
	if(cnt2 > c3) cnt2 = c3;
	if(cnt1 + cnt2 < ans) ans = cnt1 + cnt2;
	printf("%d\n",ans);
	return 0;
}