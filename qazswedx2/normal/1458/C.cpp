#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int v[3];
	pt(){memset(v,0,sizeof(v));}
}s;
int t,n,m,a[1005][1005],p[3],rp[3],ans[1005][1005];
char str[1000005];
int F(int x)
{
	int nw=(x%n+n)%n;
	if(nw==0) nw=n;
	return nw;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		s=pt();
		p[0]=0,p[1]=1,p[2]=2;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		scanf("%s",str+1);
		for(int i=1;i<=m;i++)
		{
			if(str[i]=='U') s.v[0]--;
			if(str[i]=='D') s.v[0]++;
			if(str[i]=='L') s.v[1]--;
			if(str[i]=='R') s.v[1]++;
			if(str[i]=='I') swap(s.v[1],s.v[2]),swap(p[1],p[2]);
			if(str[i]=='C') swap(s.v[0],s.v[2]),swap(p[0],p[2]);
		}
		for(int i=0;i<3;i++)
			rp[p[i]]=i;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				pt nw=s;
				nw.v[rp[0]]+=i;
				nw.v[rp[1]]+=j;
				nw.v[rp[2]]+=a[i][j];
				ans[F(nw.v[0])][F(nw.v[1])]=F(nw.v[2]);
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}