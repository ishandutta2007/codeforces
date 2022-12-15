#include<cstdio>
#include<cstring>

long long n,m,ans,k;

int main()
{
	scanf("%I64d%I64d",&n,&m);
	if (n>=m-1) {ans=(m-1)/2; printf("%I64d\n",ans); return 0;}
	k=m-n;
	if (k>=n) {printf("0\n"); return 0;}
	ans=(n-k+1)/2;
	printf("%I64d\n",ans);
	return 0;
}