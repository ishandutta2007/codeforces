// Author: Little09
// Problem: CF85D Sum of Medians
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF85D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=100005;
int n,m; 
int a[3][N],b[N],cnt;
ll s[N*4][5],c[N*4];
void push_up(int u)
{
	c[u]=c[u*2]+c[u*2+1];
	for (int i=0;i<5;i++) 
	{
		s[u][i]=s[u*2][i]+s[u*2+1][(N+i-c[u*2])%5];
	}
}
void update(int u,int l,int r,int x,ll y)
{
	if (l==r)
	{
		s[u][1]+=y;
		if (y>0) c[u]++;
		else c[u]--;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) update(u*2,l,mid,x,y);
	else update(u*2+1,mid+1,r,x,y);
	push_up(u);
}

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
int readstring()
{
	char x;
	for (int i=1;i<=3;i++) x=readchar();
	if (x=='d') return 1;
	if (x=='m') return 3;
	return 2;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int tp=readstring();
		a[0][i]=tp;
		if (tp==1) 
		{
			a[1][i]=read();
			b[++cnt]=a[1][i];
		}
		else if (tp==2) a[1][i]=read();
	}
	sort(b+1,b+cnt+1);
	for (int i=1;i<=n;i++)
	{
		if (a[0][i]==3) continue;
		a[2][i]=lower_bound(b+1,b+cnt+1,a[1][i])-b;
	}
	for (int i=1;i<=n;i++)
	{
		int tp=a[0][i];
		if (tp==1)
		{
			update(1,1,cnt,a[2][i],a[1][i]);
		}
		else if (tp==2)
		{
			update(1,1,cnt,a[2][i],-a[1][i]);
		}
		else
		{
			printf("%lld\n",s[1][3]);
		}
	}
	return 0;
}