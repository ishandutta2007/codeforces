#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005][2];
void print()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if((a[i][0]+a[i][1])%2) cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
		if((a[i][0]+a[i][1])%2)
			printf("%d ",i);
}
void getans()
{
	int fl0=0,fl1=0;
	for(int i=1;i<=n;i++)
	{
		if((a[i][0]+a[i][1])%2==0) fl0=1;
		else fl1=1;
	}
	if(fl0&&fl1)
	{
		print();
		return;
	}
	if(fl1)
	{
		for(int i=1;i<=n;i++)
			a[i][0]--;
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i][0],y=a[i][1];
		a[i][0]=(x+y)/2;
		a[i][1]=(x-y)/2;
	}
	getans();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i][0],&a[i][1]);
	getans();
	return 0;
}