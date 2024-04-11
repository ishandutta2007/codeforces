#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,p[1000005],t,b[1000005],bt,vis[1000005];
int query(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n+1;i++)
			p[i]=vis[i]=0;
		int ct=0;
		for(int i=1;i<=n;i++)
			if(!p[i])
			{
				bt=0;
				ct++;
				while(1)
				{
					b[++bt]=query(i);
					t++;
					if(vis[b[bt]]==ct) break;
					vis[b[bt]]=ct;
				}
				for(int j=1;j<bt;j++)
					p[b[j]]=b[j+1];
			}
		printf("! "); 
		for(int i=1;i<=n;i++)
			printf("%d ",p[i]);
		printf("\n");
		fflush(stdout);
	}
}