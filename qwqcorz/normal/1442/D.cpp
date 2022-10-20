#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e3+5;
const int LOG=15;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
vector<int>a[N];
int n,k,dp[N],f[LOG][N],tot[N],sum[N],ans=0;
void divide(int l,int r,int level,int num)
{
	if (l==r)
	{
//		print(l,' ');print(r);
//		for (int i=0;i<=k;i++) print(dp[i],' ');puts("");
		memcpy(f[level],dp,sizeof(dp));
		num+=tot[l];
		num=min(num,k);
		ans=max(ans,dp[k]);
		for (int i=1,Sum=a[l][1];i<=min(tot[l],k);Sum+=a[l][++i])
		ans=max(ans,dp[k-i]+Sum);
		memcpy(dp,f[level],sizeof(dp));
		return;
	}
	int mid=(l+r)/2,lnum=num;
	memcpy(f[level],dp,sizeof(dp));
	for (int i=l;i<=mid;i++)
	{
		num+=tot[i];
		num=min(num,k);
		for (int j=num;j>=tot[i];j--)
		dp[j]=max(dp[j],dp[j-tot[i]]+sum[i]);
	}
	divide(mid+1,r,level+1,num);
	num=lnum;
	memcpy(dp,f[level],sizeof(dp));
	for (int i=mid+1;i<=r;i++)
	{
		num+=tot[i];
		num=min(num,k);
		for (int j=num;j>=tot[i];j--)
		dp[j]=max(dp[j],dp[j-tot[i]]+sum[i]);
	}
	divide(l,mid,level+1,num);
	memcpy(dp,f[level],sizeof(dp));
}

signed main()
{
	memset(dp,0,sizeof(dp));
	n=read();
	k=read();
	for (int i=1;i<=n;i++)
	{
		sum[i]=0;
		tot[i]=read();
		a[i].clear();
		a[i].push_back(0);
		for (int j=1;j<=tot[i];j++)
		{
			int x=read();
			a[i].push_back(x);
			sum[i]+=x;
		}
	}
	divide(1,n,1,0);
	print(ans);

	return 0;
}