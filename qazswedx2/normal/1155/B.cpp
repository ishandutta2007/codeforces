#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,sum=0,cnt=0,maxn;
char s[100005];
int main()
{
	scanf("%d%s",&n,s+1);
	maxn=(n-11)/2;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='8') cnt++;
		else sum++;
		if(cnt==maxn+1)
		{
			if(sum<=maxn) printf("YES");
			else printf("NO");
			return 0;
		}
	}
	printf("NO");
	return 0;
}