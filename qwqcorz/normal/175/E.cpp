#include<bits/stdc++.h>
using namespace std;
const int N=70;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
void up(double &x,double y){if (x<y) x=y;}
double ans=0,r1,r2,r,b[N],sum[N],dp[20][25][25];
int n,m,s,d1,d2,t[N],cnt=0,c[N],L[N],R[N],L1[N],R1[N],L2[N],R2[N];
void solve()
{
	memset(c,0,sizeof(c));
	for (int i=1;i<=11;i++) c[L[i]]+=t[i],c[R[i]]-=t[i];
	for (int i=1;i<=cnt;i++) c[i]+=c[i-1];
	for (int i=cnt-1;i>=1;i--) sum[i]=sum[i+1]+(b[i+1]-b[i])*(c[i]+1);
	for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++) dp[0][i][j]=0;
	for (int i=1;i<=11;i++)
	{
		for (int j=0;j<=n;j++)
		for (int k=0;k<=m;k++) dp[i][j][k]=0;
		for (int j=0;j<=n;j++)
		for (int k=0;k<=m;k++)
		for (int x=0;x+t[i]<=2;x++)
		for (int y=0;x+y+t[i]<=2;y++)
		up(dp[i][j+x][k+y],dp[i-1][j][k]+x*(sum[L1[i]]-sum[R1[i]])*d1+y*(sum[L2[i]]-sum[R2[i]])*d2);
	}
	ans=max(ans,dp[11][n][m]);
}
void dfs(int now,int tot)
{
	if (tot>s) return;
	if (now>11) return tot==s?solve():void();
	for (int i=0;i<=2;i++) t[now]=i,dfs(now+1,tot+i);
}

signed main()
{
	n=read(),m=read(),s=read();
	r1=read(),r2=read(),r=read();
	d1=read(),d2=read();
	r1=sqrt(r1*r1-1),r2=sqrt(r2*r2-1),r=sqrt(r*r-1);
	for (int i=1;i<=11;i++)
	{
		b[++cnt]=i-r1;
		b[++cnt]=i+r1;
		b[++cnt]=i-r2;
		b[++cnt]=i+r2;
		b[++cnt]=i-r;
		b[++cnt]=i+r;
	}
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=11;i++) L[i]=lower_bound(b+1,b+1+cnt,i-r)-b;
	for (int i=1;i<=11;i++) R[i]=lower_bound(b+1,b+1+cnt,i+r)-b;
	for (int i=1;i<=11;i++) L1[i]=lower_bound(b+1,b+1+cnt,i-r1)-b;
	for (int i=1;i<=11;i++) R1[i]=lower_bound(b+1,b+1+cnt,i+r1)-b;
	for (int i=1;i<=11;i++) L2[i]=lower_bound(b+1,b+1+cnt,i-r2)-b;
	for (int i=1;i<=11;i++) R2[i]=lower_bound(b+1,b+1+cnt,i+r2)-b;
	dfs(1,0);
	printf("%.9lf",ans);
	
	return 0;
}