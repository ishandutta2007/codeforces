#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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
int n,m,bl,nans,nl,nr,a[M],rr[M],t[M],f[M][25];

int check(int u,int x)
{
	for (int i=20;i>=0;i--)
		if ((1<<i)&x)u=f[u][i];
	return u;
}

signed main()
{
	n=read(),m=read();bl=sqrt(n);
	for (int i=1;i<=n;i++)a[i]=read();
	rr[n+1]=n;
	for (int i=n;i>=1;i--)
	{
		int pp=a[i];rr[i]=n;
		for (int j=2;j*j<=pp;j++)
			if (pp%j==0)
			{
				while(pp%j==0)pp/=j;
				rr[i]=min(rr[i],t[j]==0?n:t[j]-1);
				t[j]=i;
			}
		if (pp!=1)rr[i]=min(rr[i],t[pp]==0?n:t[pp]-1),t[pp]=i;
		rr[i]=min(rr[i],rr[i+1]);
	}
	for (int i=1;i<=n+1;i++)
		f[i][0]=rr[i]+1;
	for (int i=1;i<=20;i++)
		for (int j=1;j<=n+1;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	while(m--)
	{
		int l=read(),r=read();
		int tl=0,tr=n,p;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (check(l,Mid)>r)p=Mid,tr=Mid-1;
			else tl=Mid+1;
		}printf("%lld\n",p);
	}
	return 0;
}
/*
6 1
2 3 10 7 5 14
3 5

*/