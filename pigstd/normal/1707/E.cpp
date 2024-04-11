#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1e5+10;
int n,q,a[M],lg2[M];
pii f[40][20][M];

pii operator + (pii a,pii b){return mp(min(a.x,b.x),max(a.y,b.y));}

pii work(int t,pii x)
{
	if (x.x==x.y)return f[t][0][x.x];
	int k=lg2[x.y-x.x]+1;
	return f[t][k][x.x]+f[t][k][x.y-(1<<(k-1))];
}

signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=2;i<=n;i++)lg2[i]=lg2[i>>1]+1;
	for (int t=0;t<=36;t++)
	{
		if (!t)
		{
			for (int i=1;i<=n;i++)f[0][0][i]=mp(a[i],a[i]);
			for (int i=1;i<n;i++)f[0][1][i]=mp(min(a[i],a[i+1]),max(a[i],a[i+1]));
		}
		else
		{
			for (int i=1;i<=n;i++)f[t][0][i].x=f[t][0][i].y=f[t-1][0][f[t-1][0][i].x].x;
			for (int i=1;i<n;i++)
				f[t][1][i]=work(t-1,f[t-1][1][i]);
		}
//		for (int i=1;i<n;i++)cout<<f[t][1][i].x<<' '<<f[t][1][i].y<<'\n';
//		puts("-----");
		for (int i=2;i<=18;i++)
			for (int j=1;j+(1<<(i-1))<=n;j++)
				f[t][i][j]=f[t][i-1][j]+f[t][i-1][j+(1<<(i-2))];
	}
	while(q--)
	{
		int l=read(),r=read();
		ll ans=0;pii now=mp(l,r);
		if (l==1&&r==n){puts("0");continue;}
		for (int i=36;i>=0;i--)
			if (work(i,now)!=mp(1,n))now=work(i,now),ans|=1ll<<i;
		ans++;
		if (ans>1ll*n*n)puts("-1");
		else cout<<ans<<'\n';
	}
	return 0;
}