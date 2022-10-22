#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e5+10;
int dp[M][2],f[M][2],n,m,a[M],l[M][2],r[M][2],sum[M][2];

struct ST1// l max
{
	int a[M],f[M][25],lg2[M];
	void init()
	{
		for (int i=1;i<=n;i++)f[i][0]=a[i];
		for (int i=2;i<=n;i++)lg2[i]=lg2[i/2]+1;
		for (int i=1;i<=20;i++)
			for (int j=1;j+(1<<(i-1))<=n;j++)
				f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	}
	int query(int l,int r)
	{
		int k=lg2[r-l+1];
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
}T1[2];
struct ST2//r min
{
	int a[M],f[M][25],lg2[M];
	void init()
	{
		for (int i=1;i<=n;i++)f[i][0]=a[i];
		for (int i=2;i<=n;i++)lg2[i]=lg2[i/2]+1;
		for (int i=1;i<=20;i++)
			for (int j=1;j+(1<<(i-1))<=n;j++)
				f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	}
	int query(int l,int r)
	{
		int k=lg2[r-l+1];
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
}T2[2];

int find1(int x,int k)
{
	int tl=x,tr=n,p=x-1;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (sum[Mid][k]-sum[x-1][k]==Mid-x+1&&
		a[x-1]>=T1[k^1].query(x,Mid)&&a[x-1]<=T2[k^1].query(x,Mid))
		p=Mid,tl=Mid+1;
		else tr=Mid-1;
	}return p;
}
/*
int find2(int x,int k)
{
	for (int i=x;i<=n;i++)
		if (l[i][k]>a[i]||r[i][k]<a[i]||l[i][k^1]>a[x-1]||r[i][k^1]<a[x-1])
			return i-1;
	return n;
}
*/

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),l[i][0]=read(),r[i][0]=read(),l[i][1]=read(),r[i][1]=read();
		if (a[i]<=r[i][0]&&a[i]>=l[i][0])sum[i][0]=1;
		if (a[i]<=r[i][1]&&a[i]>=l[i][1])sum[i][1]=1;
		T1[0].a[i]=l[i][0],T1[1].a[i]=l[i][1]; 
		T2[0].a[i]=r[i][0],T2[1].a[i]=r[i][1];
	}
	T1[0].init(),T1[1].init(),T2[0].init(),T2[1].init();
	for (int i=1;i<=n;i++)sum[i][0]+=sum[i-1][0],sum[i][1]+=sum[i-1][1];
	f[n+1][0]=f[n+1][1]=n+1;
	for (int i=n;i>=1;i--)
	{
		f[i][0]=f[i+1][0],f[i][1]=f[i+1][1];
		if (find1(i,0)>=f[i+1][1]-1)dp[i][0]=1,f[i][0]=i;
		if (find1(i,1)>=f[i+1][0]-1)dp[i][1]=1,f[i][1]=i;
//		cout<<find1(i,0)<<' '<<find1(i,1)<<endl;
//		cout<<find2(i,0)<<' '<<find2(i,1)<<endl;
	}
//	for (int i=n-1;i>=0;i--)
//		cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<endl;
	if (dp[1][0])
	{
		puts("Yes");
		int opt=0,now=1;
		while(now<=n)
		{
			for (int i=now;i<f[now+1][opt^1];i++)
				cout<<opt<<' ';
			now=f[now+1][opt^1],opt^=1;
		}//cout<<opt<<endl;
	}
	else if (dp[1][1])
	{
		puts("Yes");
		int opt=1,now=1;
		while(now<=n)
		{
			for (int i=now;i<f[now+1][opt^1];i++)
				cout<<opt<<' ';
			now=f[now+1][opt^1],opt^=1;
		}//cout<<opt<<endl; 
	}
	else puts("No");
	return 0;
}