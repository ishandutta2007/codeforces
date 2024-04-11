#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,k,vis[105];
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&n,&k,s+1);
		int ans=0;
		for(int i=1;i<=(k+1)/2;i++)
		{
			for(int j=0;j<26;j++)
				vis[j]=0;
			int ct=0,mx=0;
			for(int j=0;j<n;j+=k)
			{
				ct++;
				vis[s[i+j]-'a']++;
				if(i+j!=j+k+1-i) ct++,vis[s[j+k+1-i]-'a']++;
			}
			for(int j=0;j<26;j++)
			{
				//printf("i=%d,j=%d,vis=%d\n",i,j,vis[j]);
				mx=max(mx,vis[j]);
			}
			ans+=ct-mx;
		}
		printf("%d\n",ans);
	}
	return 0;
}