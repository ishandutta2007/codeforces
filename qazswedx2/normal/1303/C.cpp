#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,f[105][105],vis[105],tt;
char s[100005],tans[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		tt=0;
		for(int i=0;i<26;i++)
			for(int j=0;j<26;j++)
				f[i][j]=0;
		for(int i=0;i<26;i++)
			vis[i]=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<n;i++)
		{
			f[s[i]-'a'][s[i+1]-'a']=1;
			f[s[i+1]-'a'][s[i]-'a']=1;
		}
		int fl=1;
		for(int i=0;i<26;i++)
		{
			int ct=0;
			for(int j=0;j<26;j++)
				ct+=f[i][j];
			if(ct>2)
			{
				printf("NO\n");
				fl=0;
				break;
			}
		}
		if(!fl) continue;
		for(int i=0;i<26;i++)
		{
			if(vis[i]) continue;
			int ct=0;
			for(int j=0;j<26;j++)
				ct+=f[i][j];
			if(!ct) tans[++tt]=i+'a';
			if(ct==1)
			{
				tans[++tt]=i+'a';
				vis[i]=1;
			//	printf("i=%d\n",i);
				int u=i;
				while(1)
				{
					int v=-1;
					for(int j=0;j<26;j++)
					{
						//printf("j=%d,%d,%d\n",j,f[u][j],!vis[j]);
						if(f[u][j]&&!vis[j])
							v=j;
					}
					//printf("v=%d\n",v);
					if(v==-1) break; 
					vis[v]=1;
					tans[++tt]=v+'a';
					u=v;
				}
			}
		}
		if(tt!=26)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<=26;i++)
			printf("%c",tans[i]);
		printf("\n");
	}
	return 0;
}