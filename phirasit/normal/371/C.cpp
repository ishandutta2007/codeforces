#include <stdio.h>
#include <limits.h>

#define LL unsigned long long
#define INF 3000000000000

char str[110];
LL nb,ns,nc;
LL b,s,c,r;

int main() {
	int i,j;
	scanf("%s",str);
	scanf("%I64d %I64d %I64d",&nb,&ns,&nc);
	scanf("%I64d %I64d %I64d %I64d",&b,&s,&c,&r);
	LL cb,cs,cc;
	cb = cs = cc = 0;
	for(i=0;str[i];i++) {
		if(str[i] == 'B') {
			cb++;
		}else if(str[i] == 'S') {
			cs++;
		}else {
			cc++;
		}
	}
	LL A = 0,B = INF;
	while(A < B) {
		LL m = (A+B)/2+1;
		LL x = 0;
		if(cb*m > nb) x += b*(cb*m-nb);
		if(cs*m > ns) x += s*(cs*m-ns);
		if(cc*m > nc) x += c*(cc*m-nc);
		if(x <= r)
			A = m;
		else
			B = m-1;
	}
	printf("%I64d\n", A);
	return 0;
}