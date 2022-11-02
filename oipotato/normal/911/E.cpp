#include<cstdio>
#include<algorithm>
using namespace std;
int s[200010],a[200010],n,k,top;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
	}
	int now=1,t=1;
	for(;;)
	{
		for(;top&&s[top]==now;)
		{
			now++;
			top--;
		}
		int pos=-1;
		for(;t<=k;)
		{
			if(a[t]==now)
			{
				pos=t;
				break;
			}
			if(top&&a[t]>s[top])
			{
				puts("-1");
				return 0;
			}
			s[++top]=a[t];
			t++;
		}
		if(pos==-1)
		{
			break;
		}
		t++;now++;
	}
	for(;top;)
	{
		if(s[top]==now)
		{
			top--;
			now++;
			continue;
		}
		for(int i=s[top]-1;i>=now;i--)
		{
			a[++k]=i;
		}
		now=s[top]+1;
		top--;
	}
	for(int i=n;i>=now;i--)
	{
		a[++k]=i;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d%c",a[i],i==n?'\n':' ');
	}
	return 0;
}