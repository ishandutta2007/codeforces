#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,b[1000005],c[1000005],bt,ct,tt;
long long a[1000005],tans[1000005][3];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u]+=w;
		a[v]-=w;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>0) b[++bt]=i;
		if(a[i]<0) c[++ct]=i;
	}
	for(int i=bt;i>=1;i--)
	{
		while(a[b[i]]>0)
		{
			tt++;
			tans[tt][0]=b[i],tans[tt][1]=c[ct];
			tans[tt][2]=min(a[b[i]],-a[c[ct]]);
			if(a[b[i]]<-a[c[ct]])
			{
				a[c[ct]]+=a[b[i]];
				a[b[i]]=0;
			}
			else
			{
				a[b[i]]+=a[c[ct]];
				ct--;
			}
			//printf("a=%lld,ct=%d\n",a[b[i]],ct);
		}
	}
	printf("%d\n",tt);
	for(int i=1;i<=tt;i++)
		printf("%I64d %I64d %I64d\n",tans[i][0],tans[i][1],tans[i][2]);
	return 0;
}