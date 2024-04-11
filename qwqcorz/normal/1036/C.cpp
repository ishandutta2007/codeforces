#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+5;

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
int a[N],cnt=0,Pow[28];

signed main()
{
	Pow[0]=1;
	for (int i=1;i<=17;i++) Pow[i]=Pow[i-1]*10;
	for (int i=0;i<=17;i++)
	for (int ii=0;ii<=9;ii++)
	for (int j=0;j<i;j++)
	for (int jj=0;jj<=9;jj++)
	for (int k=0;k<j;k++)
	for (int kk=0;kk<=9;kk++)
	a[++cnt]=Pow[i]*ii+Pow[j]*jj+Pow[k]*kk;
	sort(a+1,a+1+cnt);
	cnt=unique(a+1,a+1+cnt)-a-1;
//	for (int i=1;i<=cnt;i++) print(a[i]);
	int T=read();
	while (T--)
	{
		int l=read(),r=read();
		int L=upper_bound(a+1,a+1+cnt,l-1)-a-1;
		int R=upper_bound(a+1,a+1+cnt,r  )-a-1;
		print(R-L+(r==1e18));
	}

	return 0;
}