#include<cstdio>
using namespace std;
int n,a,b,c,x,ans;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x==1)
		{
			if(a)a--;
			else if(b)
			{
				b--;
				c++;
			}
			else if(c)c--;
			else ans++;
		}
		else
		{
			if(b)b--;
			else ans+=2;
		}
	}
	printf("%d",ans);
	return 0;
}