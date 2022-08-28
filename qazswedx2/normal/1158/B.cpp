#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,a[1000005];
int main()
{
	scanf("%d%d",&n,&k);
	int x=(n-k+2)/2;
	for(int i=x;i<=n;i+=x)
		a[i]=1;
	for(int i=1;i<=n;i++)
		printf("%d",a[i]);
	return 0;
}