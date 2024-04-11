#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2505;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

ll ans=0;
char s[N];
int a[N][N],sum[N][N],n,m,k;
int calc(int x1,int y1,int x2,int y2)
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
void solve(int x1,int x2,int y1,int y2)
{
	if (x1==x2&&y1==y2) return ans+=a[x1][y1]==k,void();
	if (x2-x1>=y2-y1)
	{
		int mid=(x1+x2)/2;
		solve(x1,mid,y1,y2);
		solve(mid+1,x2,y1,y2);
		for (int i=y1;i<=y2;i++)
		{
			int w1[7]={x1,x1,x1,x1,x1,x1,x1};
			int w2[7]={x2,x2,x2,x2,x2,x2,x2};
			for (int j=i;j<=y2;j++)
			{
				for (int t=0;t<=k;t++) while (calc(w1[t],i,mid,j)>t) w1[t]++;
				for (int t=0;t<=k;t++) while (calc(mid+1,i,w2[t],j)>t) w2[t]--;
				for (int t=0;t<=k;t++)
				ans+=((!t?mid+1:w1[t-1])-w1[t])*(w2[k-t]-(!(k-t)?mid:w2[k-t-1]));
			}
		}
	}
	else
	{
		int mid=(y1+y2)/2;
		solve(x1,x2,y1,mid);
		solve(x1,x2,mid+1,y2);
		for (int i=x1;i<=x2;i++)
		{
			int w1[7]={y1,y1,y1,y1,y1,y1,y1};
			int w2[7]={y2,y2,y2,y2,y2,y2,y2};
			for (int j=i;j<=x2;j++)
			{
				for (int t=0;t<=k;t++) while (calc(i,w1[t],j,mid)>t) w1[t]++;
				for (int t=0;t<=k;t++) while (calc(i,mid+1,j,w2[t])>t) w2[t]--;
				for (int t=0;t<=k;t++)
				ans+=((!t?mid+1:w1[t-1])-w1[t])*(w2[k-t]-(!(k-t)?mid:w2[k-t-1]));
			}
		}
	}
}

signed main()
{
	n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) sum[i][j]=a[i][j]=s[j]-'0';
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) sum[i][j]+=sum[i-1][j];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) sum[i][j]+=sum[i][j-1];
	solve(1,n,1,m);
	print(ans);
	
	return 0;
}