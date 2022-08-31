#include<cstdio>
#include<cstring> 
#include<algorithm>
using namespace std;
int n,q,sum[300005][26];
char s[200005];
int main()
{
	scanf("%s%d",s+1,&q);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<26;j++)
			if(j+'a'==s[i]) sum[i][j]=sum[i-1][j]+1;
			else sum[i][j]=sum[i-1][j];
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==r)
		{
			printf("Yes\n");
			continue;
		}
		int fl=0,ct=0;
		for(int j=0;j<26;j++)
		{
			if(sum[r][j]-sum[l-1][j]==r-l+1)
			{
				//printf("j=%d\n",j);
				fl=1;
			}
			if(sum[r][j]!=sum[l-1][j]) ct++;
		}
		if(fl) printf("No\n");
		else if(ct>=3) printf("Yes\n");
		else if(s[l]!=s[r]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}