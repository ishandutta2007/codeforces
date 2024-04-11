#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int p=998244353;

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
int get(int x)
{
	int ret=0;
	while (x)
	{
		ret++;
		x/=10;
	}
	return ret;
}
void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int Pow[28],a[N],cnt[28];

signed main()
{
	Pow[0]=1;
	int n=read(),ans=0;
	for (int i=1;i<=20;i++) Pow[i]=Pow[i-1]*10%p;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) cnt[get(a[i])-1]++;
	for (int i=1;i<=n;i++) a[i]*=10;
	for (int i=1;i<=n;i++)
	for (int j=0;a[i]/=10;j++)
	for (int k=0;k<=10;k++)
	{
		add(ans,a[i]%10*Pow[j*2  -max(j-k-1,0ll)]%p*cnt[k]%p);
		add(ans,a[i]%10*Pow[j*2+1-max(j-k  ,0ll)]%p*cnt[k]%p);
	}
	print(ans);

	return 0;
}