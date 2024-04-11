#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const ll p=1e9+7;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register ll x)
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
inline void print(const register ll x,const register char c='\n')
{
	write(x);
	putchar(c);
}
int fa[N],sum[N];
int find(int x)
{
	if (fa[x]==x) return x;
	int ret=find(fa[x]);
	sum[x]^=sum[fa[x]];
	return fa[x]=ret;
}
ll power(ll a,ll b)
{
	ll ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}

int main()
{
	memset(sum,0,sizeof(sum));
	int n=read(),m=read(),ans=-1;
	for (int i=0;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		int l=1+abs(y-x),r=n-abs(n-y-x+1);
		char c=getchar();//print(l,' ');print(r);
		while (c!='o'&&c!='x') c=getchar();
		l=max(l-2,0);
		int L=find(l),R=find(r);//print(L,',');print(R);
		if (L!=R)
		{
			sum[L]=sum[l]^sum[r]^(c=='o');
			fa[L]=R;
		}
		else if ((sum[l]^sum[r])!=(c=='o')) return puts("0"),0;
//		for (int i=0;i<=n;i++) print(sum[i],' ');puts("");
	}
	for (int i=0;i<=n;i++) ans+=fa[i]==i;
	print(power(2,ans));

	return 0;
}