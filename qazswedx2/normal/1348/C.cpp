#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,m;
char s[1000005];
//vector<char> a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&n,&m,s+1);
		sort(s+1,s+n+1);
		//for(int i=1;i<=m;i++)
		//	a[i].clear();
		if(s[1]!=s[m])
		{
			printf("%c\n",s[m]);
			continue;
		}
		if(m==n||s[m+1]==s[n])
		{
			int nw=1;
			for(int i=1;i<=n;i+=m)
				printf("%c",s[i]);
			printf("\n");
			continue;
		}
		for(int i=m;i<=n;i++)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}