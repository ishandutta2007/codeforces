#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> g[200010];
int num0,num1,n,tot,stk0[200010],stk1[200010];
char s[200010];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			if(num1)
			{
				stk0[++num0]=stk1[num1--];
				g[stk0[num0]].push_back(i);
			}
			else
			{
				stk0[++num0]=++tot;
				g[tot].push_back(i);
			}
		}
		else
		{
			if(num0)
			{
				stk1[++num1]=stk0[num0--];
				g[stk1[num1]].push_back(i);
			}
			else
			{
				puts("-1");
				return 0;
			}
		}
	}
	if(num1)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
	{
		printf("%d",g[i].size());
		for(int j:g[i])
		{
			printf(" %d",j);
		}
		puts("");
	}
	return 0;
}