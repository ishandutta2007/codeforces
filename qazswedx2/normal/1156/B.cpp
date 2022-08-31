#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,a[105],n,mx,mn,b[105],c[105],bt,vis[105];
char s[100005],ans[100005],tans=0;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		scanf("%s",s);
		n=strlen(s);
		for(int i=0;s[i];i++)
			a[s[i]-'a']++;
		int fl=0,len=0;
		bt=0;
		tans=0;
		mx=-9999,mn=9999;
		for(int i=0;i<26;i++)
		{
			if(a[i]&&!fl) fl=1,len=1;
			else if(!a[i]&&fl) 
			{
				fl=0;
				b[++bt]=i-len;
				c[bt]=i-1;
			}
			else if(a[i]&&fl) len++;
		}
		//for(int i=1;i<=bt;i++)
		//	printf("b=%d,c=%d\n",b[i],c[i]);
		if(fl)
		{
			b[++bt]=25-len+1;
			c[bt]=25;
		}
		if(bt>1)
		{
			for(int i=1;i<=bt;i++)
			{
				if(b[i]==c[i]) continue;
				for(int j=b[i];j<=c[i];j+=2)
				{
					for(int k=1;k<=a[j];k++)
						ans[++tans]=j;
				}
			}
			for(int i=1;i<=bt;i++)
				if(b[i]==c[i])
					for(int j=1;j<=a[b[i]];j++)
						ans[++tans]=b[i];
			for(int i=1;i<=bt;i++)
				for(int j=b[i]+1;j<=c[i];j+=2)
					for(int k=1;k<=a[j];k++)
						ans[++tans]=j;
			for(int i=1;i<=tans;i++)
				printf("%c",ans[i]+'a');
		}
		else
		{
			if(c[1]==b[1])
			{
				for(int i=1;i<=n;i++)
					printf("%c",b[1]+'a');
			}
			else if(c[1]-b[1]+1<=3)
			{
				printf("No answer");
			}
			else
			{
				for(int i=b[1]+1;i<=c[1];i+=2)
					for(int j=1;j<=a[i];j++)
						ans[++tans]=i;
				for(int i=b[1];i<=c[1];i+=2)
					for(int j=1;j<=a[i];j++)
						ans[++tans]=i;
				for(int i=1;i<=tans;i++)
					printf("%c",ans[i]+'a');
			}
		}
		printf("\n");
	}
}