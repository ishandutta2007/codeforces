#include <stdio.h>

#define MOD (long long) (1e9 + 7)
#define MX_N 100010
#define LL long long

char a[MX_N],b[MX_N];
LL opt[MX_N][4];
int n;

int main() {
	int i,j;
	scanf("%d",&n);
	scanf("%s %s",a,b);
	for(i=0;i<n;i++) {
		LL w,x,y;
		if(a[i] == '?') {
			if(b[i] == '?') {
				w = 10;
				x = 45;
				y = 45;
			}else {
				w = 1;
				x = 10 - (b[i]-'0') - 1;
				y = b[i]-'0';
			}
		}else {
			if(b[i] == '?') {
				w = 1;
				x = a[i]-'0';
				y = 10 - (a[i]-'0') - 1;
			}else {
				w = (a[i] == b[i]);
				x = (a[i] > b[i]);
				y = (a[i] < b[i]);
			}
		}
		if(i == 0) {
			opt[i][0] = w;
			opt[i][1] = x;
			opt[i][2] = y;
			opt[i][3] = 0;
		}else {
			opt[i][0] = (opt[i-1][0] * w)%MOD;
			opt[i][1] = (opt[i-1][1] * (w+x) + opt[i-1][0] * x)%MOD;
			opt[i][2] = (opt[i-1][2] * (w+y) + opt[i-1][0] * y)%MOD;
			opt[i][3] = (opt[i-1][1] * y + opt[i-1][2] * x + opt[i-1][3] * (w+x+y)) % MOD;
		}
	}
	printf("%I64d\n",opt[n-1][3]);
	return 0;
}