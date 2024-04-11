#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
int main()
{
	char s[110];
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
	if(s[i]=='h')
	{
		for(int j=i+1;j<=len;j++)
		if(s[j]=='e')
		{
			for(int k=j+1;k<=len;k++)
			if(s[k]=='l')
			{
				for(int p=k+1;p<=len;p++)
				if(s[p]=='l')
				{
					for(int t=p+1;t<=len;t++)
					if(s[t]=='o')
					{
						puts("YES");
						return 0;
					}
					break;
				}
				break;
			}
			break;
		}
		break;
	}
	puts("NO");
	return 0;
}