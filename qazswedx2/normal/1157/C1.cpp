#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],las=0,l,r,bt=0;
char b[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	l=1,r=n;
	while(1)
	{
		if(l>r||(a[l]<=las&&a[r]<=las)) break;
		if(a[l]>a[r]&&a[r]>las||a[r]>a[l]&&a[l]<las)
		{
			b[++bt]='R';
			las=a[r];
			r--;
		}
		else
		{
			b[++bt]='L';
			las=a[l];
			l++;
		}
	}
	printf("%d\n",bt);
	printf("%s",b+1);
	return 0;
}