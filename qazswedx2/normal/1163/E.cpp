#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],b[105],c[105],tans[105],t,lg[1000005];
void ins(int x)
{
	int xx=x;
	for(int i=30;i>=0;i--)
		if(x&(1<<i))
		{
			if(!b[i])
			{
				b[i]=x;
				c[i]=xx;
				return;
			}
			x^=b[i];
		}
}
int main()
{
	for(int i=0;i<=18;i++)
		lg[1<<i]=i;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ins(a[i]);
		int lim=1,len=0,fl=0;
		while(lim<=a[i]) lim<<=1,len++;
		for(int j=0;j<len;j++)
			if(!b[j])
			{
				fl=1;
				break;
			}
		if(!fl)
		{
			if(t<len)
			{
				t=len;
				for(int j=0;j<len;j++)
					tans[j]=c[j];
			}
		}
	}
	printf("%d\n",t);
	int nw=0;
	for(int i=0;i<(1<<t);i++)
	{
		printf("%d ",nw);
		nw^=tans[lg[(i+1)&(-(i+1))]];
	}
	return 0;
}