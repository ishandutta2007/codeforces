#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,vis1[105],vis2[105];
char s1[200005],s2[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<26;i++)
			vis1[i]=vis2[i]=0;
		scanf("%d%s%s",&n,s1+1,s2+1);
		for(int i=1;i<=n;i++)
		{
			//printf("%d %d\n",(int)s1[i]-'a',(int)s2[i]-'a');
			vis1[s1[i]-'a']++,vis2[s2[i]-'a']++;
		}
		//printf("-");
		int fl=1;
		for(int i=0;i<26;i++)
			if(vis1[i]!=vis2[i])
			{
				printf("No\n");
				fl=0;
				break;
			}
		if(!fl) continue;
		for(int i=0;i<26;i++)
			if(vis1[i]>1)
				fl=0;
		if(!fl)
		{
			printf("Yes\n");
			continue;
		}
		int ct1=0,ct2=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(s1[i]<s1[j]) ct1++;
				if(s2[i]<s2[j]) ct2++;
			}
		if(ct1%2==ct2%2) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}