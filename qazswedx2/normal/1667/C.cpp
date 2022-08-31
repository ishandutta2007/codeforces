#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p[100005];
int main()
{
	scanf("%d",&n);
	int m=(2*n+1)/3;
	for(int i=1;i<=m;i++)
		p[i]=i;
	reverse(p+1,p+(m-1)/2+1);
	reverse(p+m/2+1,p+m+1);
	printf("%d\n",m);
	for(int i=1;i<=m;i++)
		printf("%d %d\n",i,p[i]);
	return 0;
}