#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[200005],b[105],cnt,sum;
void insert(int x)
{
	for(int i=30;i>=0;i--)
		if((1<<i)&x)
		{
			if(!b[i]) 
			{
				b[i]=x,cnt++;
				return;
			}
			else x^=b[i];
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum^=a[i];
	if(sum==0)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		insert(a[i]);
	printf("%d",cnt);
	return 0;
}