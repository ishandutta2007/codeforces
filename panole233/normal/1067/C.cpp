#include<cstdio>
#include<cstring>

int n;

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n/3; i++) printf("%d %d\n%d %d\n%d %d\n",2*i-1,1,2*i,1,2*i,4);
	for (int i=n/3*3+1; i<=n; i++) printf("%d %d\n",2*(n/3+1)-1,n-i+1);
	return 0;
}