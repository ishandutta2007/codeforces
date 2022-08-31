#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxlen 12
struct pt
{
	int len;
	bool vis[14][35005];
	int fr[105],las[105];
	pt()
	{
		len=0;
		memset(vis,0,sizeof(vis));
		memset(fr,0,sizeof(fr));
		memset(las,0,sizeof(las));
	}
}a[205];
int n,m;
char s[10005];
pt merge(const pt& x,const pt& y)
{
	pt ans;
	int xl=min(maxlen,x.len),yl=min(maxlen,y.len);
	ans.len=x.len+y.len;
	if(ans.len>1000000) ans.len=1000000;
	for(int i=1;i<=maxlen;i++)
		for(int j=0;j<(1<<i);j++)
			ans.vis[i][j]=x.vis[i][j]|y.vis[i][j];
	for(int i=1;i<=xl;i++)
		s[i]=x.las[i];
	for(int i=xl+1,j=1;j<=yl;i++,j++)
		s[i]=y.fr[j];
	for(int i=1;i<=xl+yl;i++)
	{
		int sum=0;
		for(int k=1;k<=maxlen&&i+k-1<=xl+yl;k++)
		{
			sum=sum*2+s[i+k-1];
			ans.vis[k][sum]=1;
		}
	}
	for(int i=1;i<=xl;i++)
		ans.fr[i]=x.fr[i];
	if(x.len<maxlen)
	{
		for(int i=1;i<=maxlen-x.len;i++)
			ans.fr[i+x.len]=y.fr[i];
	}
	if(y.len>=maxlen)
	{
		for(int i=1;i<=maxlen;i++)
			ans.las[i]=y.las[i];
	}
	else
	{
		int al=min(maxlen,ans.len);
		for(int i=al,j=y.len;j>0;i--,j--)
			ans.las[i]=y.las[j];
		for(int i=al-y.len,j=xl;i>0;i--,j--)
			ans.las[i]=x.las[j];
	}
	return ans;
}
void print(const pt& x)
{
	int xl=min(maxlen,x.len);
	printf("len=%d,fr=",x.len);
	for(int i=1;i<=xl;i++)
		printf("%d ",x.fr[i]);
	printf(",las=");
	for(int i=1;i<=xl;i++)
		printf("%d ",x.las[i]);
	printf(",vis=");
	for(int i=1;i<=maxlen;i++)
		for(int j=0;j<(1<<i);j++)
		{
			if(x.vis[i][j]) printf("<%d,%d>",i,j);
		}
		//if(x.vis[i])
	//	printf("%d ",i);
	printf("\n");
} 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		a[i].len=strlen(s+1);
		for(int j=1;j<=a[i].len;j++)
		{
			int sum=0;
			for(int k=1;k<=maxlen&&j+k-1<=a[i].len;k++)
			{
				sum=sum*2+s[j+k-1]-'0';
				a[i].vis[k][sum]=1;
			}
			//printf("j=%d\n",j);
		}
		//printf("---");
		int tmax=min(a[i].len,maxlen);
		for(int j=1;j<=tmax;j++)
			a[i].fr[j]=s[j]-'0';
		for(int j=a[i].len-tmax+1,k=1;j<=a[i].len;j++,k++)
			a[i].las[k]=s[j]-'0';
		//printf("a[%d]=",i);
		//print(a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[n+i]=merge(a[x],a[y]);
		/*if(a[n+i].vis[0]==0||a[n+i].vis[1]==0)
		{
			printf("0\n");
			continue;
		}*/
		//printf("a[%d]=",n+i);
		//print(a[n+i]);
		for(int j=1;j<=maxlen;j++)
		{
			int ffl=1;
			for(int k=0;k<(1<<j);k++)
				if(!a[n+i].vis[j][k])
				{
					ffl=0;
					break;
				}
			if(!ffl)
			{
				printf("%d\n",j-1);
				break;
			}
		}
	}
	return 0;
}