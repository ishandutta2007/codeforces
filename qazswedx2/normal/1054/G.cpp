#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
struct edge
{
	int u,v;
	edge(int u=0,int v=0):u(u),v(v){}
};
typedef bitset<2005> bint;
bint tmp[4005],*tp,a[2005];
int t,n,m,vis[2005],ffl;
char s[100005];
vector<edge> solve()
{
//	printf("solve:a=\n");
/*	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d",(int)a[i][j]);
		printf("\n");
	}*/
	bint nw;
	nw.set();
	int fl=0;
	for(int i=1;i<=m;i++)
	{
		bint q=nw&a[i];
		if(q.count()>1) nw=q,fl=1;
	}
	vector<edge> ans;
	if(!fl)
	{
		int las=-1;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				if(las!=-1) ans.push_back(edge(las,i));
				las=i;
			}
		return ans;
	}
	int len=nw.count();
	bint *f=tp;
	tp+=len;
	for(int i=0;i<len;i++)
		f[i].reset();
	int b[2005],bt=0;
	for(int i=1;i<=n;i++)
		if(nw[i])
			b[bt++]=i;
	for(int i=1;i<len;i++)
		vis[b[i]]=1;
	for(int i=1;i<=m;i++)
	{
		int fl=0,id=0,ct=0;
		for(int j=0;j<len;j++)
			if(a[i][b[j]]) fl=1,id=j,ct++;
		if(ct==1) f[id]|=a[i];
		a[i][b[0]]=fl;
		for(int j=1;j<len;j++)
			a[i][b[j]]=0;
	}
	ans=solve();
	if(ffl==1) return ans;
	int sz=ans.size();
/*	printf("b=");
	for(int i=0;i<len;i++)
		printf("%d ",b[i]);
	printf("\nans=");
	for(int i=0;i<sz;i++)
		printf("(%d,%d) ",ans[i].u,ans[i].v);
	printf("\n");*/
	for(int i=0;i<sz;i++)
	{
		int u=ans[i].u,v=ans[i].v;
		if(v==b[0]) swap(u,v);
		if(u==b[0])
		{
			int id=0,ct=0;
			for(int j=0;j<len;j++)
				if(f[j][v])
				{
					id=j;
					ct++;
				}
			if(ct>1)
			{
				ffl=1;
				return ans;
			}
			ans[i]=edge(b[id],v);
		}
	}
	for(int i=1;i<len;i++)
		ans.push_back(edge(b[i-1],b[i]));
/*	printf("ans=");
	for(int i=0;i<sz;i++)
		printf("(%d,%d) ",ans[i].u,ans[i].v);
	printf("\n");*/
	return ans;
}
int main()
{
//	freopen("CF1054G.in","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		tp=tmp;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%s",s+1);
			a[i].reset();
			for(int j=1;j<=n;j++)
				a[i][j]=s[j]-'0';
		}
		ffl=0;
		vector<edge> ans=solve();
		if(ffl)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			int sz=ans.size();
			for(int i=0;i<sz;i++)
				printf("%d %d\n",ans[i].u,ans[i].v);
		}
	}
	return 0;
}