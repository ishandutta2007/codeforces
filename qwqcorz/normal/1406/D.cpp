#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;

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
void Print(int x)
{
	if (x&1) x++;
	print(x/2);
}
int n,Max1=0,Max2=0,a[N];
void add(int l,int x)
{
	l--;
	if (l==0) Max1+=x;
	if (l<1||n<=l) return;
	if (a[l]>0) Max2-=a[l];
	a[l]+=x;
	if (a[l]>0) Max2+=a[l];
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	Max1=a[1];
	for (int i=1;i<=n;i++) a[i]=a[i+1]-a[i];
//	for (int i=n-1;i>=1;i--) print(a[i]);
	for (int i=1;i<n;i++) if (a[i]>0) Max2+=a[i];
	Print(Max1+Max2);
	int m=read();
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read(),x=read();
		add(l,x);
		add(r+1,-x);
		Print(Max1+Max2);
	}

	return 0;
}