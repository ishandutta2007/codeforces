#include <cstdio>
using namespace std;
int a[100002];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	a[n]=a[0];
	int cnt=0,s;
	for(int i=0;i<n;i++)
		if(a[i]>a[i+1])
		{
			cnt++;
			s=i;
		}
	if(cnt==0)printf("0\n");
	else if(cnt!=1)printf("-1\n");
	else printf("%d\n",n-s-1);
	return 0;
}