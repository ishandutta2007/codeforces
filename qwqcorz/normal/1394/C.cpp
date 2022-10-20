#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int inf=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char s[N];
int n,x[N],y[N],xx,yy;
bool check(int d)
{
	int lx=0,ly=0,lxy=-inf,rx=inf,ry=inf,rxy=inf;
	for (int i=1;i<=n;i++)
	{
		lx=max(lx,x[i]-d);
		ly=max(ly,y[i]-d);
		lxy=max(lxy,x[i]-y[i]-d);
		rx=min(rx,x[i]+d);
		ry=min(ry,y[i]+d);
		rxy=min(rxy,x[i]-y[i]+d);
	}
	for (int i=ly;i<=ry;i++)
	{
		int l=max(lx,lxy+i),r=min(rx,rxy+i);
		if (i==0) l=max(l,1);
		if (l<=r) return xx=r,yy=i,1;
	}
	return 0;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int A=0,B=0;
		scanf("%s",s+1);
		int m=strlen(s+1);
		for (int j=1;j<=m;j++) (s[j]=='B'?A:B)++;
		x[i]=A,y[i]=B;
	}
	int l=0,r=5e5;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
				   else l=mid+1;
	}
	check(l);
	print(l);
	for (int i=1;i<=xx;i++) putchar('B');
	for (int i=1;i<=yy;i++) putchar('N');
	
	return 0;
}