#include<bits/stdc++.h>
using namespace std;
const int N=200;
const int M=6e4+1e3;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register int x)
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
inline void print(const register int x,const register char c='\n')
{
	write(x);
	putchar(c);
}
struct pro
{
	int a,b;
}x[2*N],y[2*N];
int cnt1=0,cnt2=0,ans=0,Max=0,dp[M];
bool cmp1(pro x,pro y){return x.a<y.a;}
bool cmp2(pro x,pro y){return x.a-x.b>y.a-y.b;}

int main()
{
	memset(dp,0,sizeof(dp));
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		int a=read(),b=read();
		if (b>=0) x[++cnt1]=(pro){a,b};
			 else y[++cnt2]=(pro){a,-b};
	}
	sort(x+1,x+1+cnt1,cmp1);
	sort(y+1,y+1+cnt2,cmp2);
	for (int i=1;i<=cnt1;i++) if (x[i].a<=m) m+=x[i].b,ans++;
	for (int i=1;i<=cnt2;i++)
	for (int j=0;j<=m-y[i].b;j++)
	if (j+y[i].b>=y[i].a) Max=max(Max,dp[j]=max(dp[j],dp[j+y[i].b]+1));
	print(ans+Max);

	return 0;
}