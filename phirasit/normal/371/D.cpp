/*#include <stdio.h>
#include <limits.h>
#define LL unsigned long long

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
	LL A = 0,B = LLONG_MAX;
	while(A < B) {
		LL m = (A+B)/2+1;
		printf("%I64d\n",m);
		LL x = b*(m-nb) + s*(m-ns) + c*(m-nc);
		printf(" > %I64d %I64d %I64d\n",x,r,(x <= (LL)r));
		if(x <= r)
			A = m;
		else
			B = m-1;
	}
	printf("%I64d\n",B);
	return 0;
}*/
#include <stdio.h>
#define LL long long 
#define MX_N 200010

LL limit[MX_N];
LL water[MX_N];
int father[MX_N];
int n,m;

int f(int j) {
	if(father[j] == j)
		return j;
	return father[j] = f(father[j]);
}
void update(int idx,LL val) {
	idx = f(idx);
	water[idx] += val;
	if(water[idx] > limit[idx]) {
		if(idx < n) {
			father[idx] = f(idx+1);
			update(father[idx+1],water[idx]-limit[idx]);
		}
		water[idx] = limit[idx];
	}
}
int main() {
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%I64d",&limit[i]);
		father[i] = i;
		water[i] = 0;
	}
	scanf("%d",&m);
	while(m--) {
		int a,idx;
		LL val;
		scanf("%d %d",&a,&idx);
		if(a == 1) {
			scanf("%I64d",&val);
			update(idx,val);
		}else {
			printf("%I64d\n",water[idx]);
		}
	}
	return 0;
}