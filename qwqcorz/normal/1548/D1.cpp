#include<bits/stdc++.h>
#define ll long long
using namespace std;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll ans=0;
int a[2][2];
ll C2(int n){return 1LL*n*(n-1)/2;}
ll C3(int n){return 1LL*n*(n-1)*(n-2)/6;}
ll calc(int i,int j,int k)
{
	if (i==j&&j==k) return C3(a[i>>1][i&1]);
	if (i==k) swap(j,k);
	if (j==k) swap(i,k);
	if (i==j) return C2(a[i>>1][i&1])*a[k>>1][k&1];
	return 1LL*a[i>>1][i&1]*a[j>>1][j&1]*a[k>>1][k&1];
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[!!(x%4)][!!(y%4)]++;
	}
	for (int i=0;i<4;i++)
	for (int j=i;j<4;j++)
	for (int k=j;k<4;k++)
	if ((!!(i^j)+!!(i^k)+!!(j^k))%2==0)
	ans+=calc(i,j,k);
	print(ans);
	
	return 0;
}