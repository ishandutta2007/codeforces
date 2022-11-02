#include<cstdio>
using namespace std;
int n,top,tag,now,ans,x,stack[300010];
char opt[10];
int main()
{
	scanf("%d",&n);
	now=1;
	for(int i=1;i<=n<<1;i++)
	{
		scanf("%s",opt);
		if(opt[0]=='a')
		{
			scanf("%d",&x);
			stack[++top]=x;
		}
		else
		{
			if(tag==top)
			{
				tag--;
				top--;
				now++;
				continue;
			}
			if(stack[top]==now)
			{
				top--;
				now++;
				continue;
			}
			tag=top-1;
			top--;
			now++;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}