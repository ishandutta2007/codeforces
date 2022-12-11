#include <stdio.h>

#define MX_N 210000
#define LL long long

int tmp[MX_N];
LL val[MX_N];
LL com[MX_N];
int n,m;

int search(LL x) {
	int a=0,b=n-1;
	while(a < b) {
		int m = (a+b)/2 + 1;
		if(com[m] <= x) {
			a = m;
		}else {
			b = m-1;
		}
	}
	if(val[a] == -1) {
		return search((x - com[a]) % tmp[a] + 1);
	}
	return val[a];
}
int main() {
	int i,j;
	scanf("%d",&n);
	LL l = 1;
	for(i=0;i<n;i++) {
		int a,b,c;
		scanf("%d",&a);
		if(a == 1) {
			scanf("%d",&b);
			val[i] = b;
			com[i] = l;
			l++;
		}else {
			scanf("%d %d",&b,&c);
			com[i] = l;
			tmp[i] = (LL)b;
			l += (LL)b*c;
			val[i] = -1;
		}
	}
	scanf("%d",&m);
	for(i=0;i<m;i++) {
		LL k;
		scanf("%I64d",&k);
		printf("%d ",search(k));
	}
	printf("\n");
	return 0;
}