#include<bits/stdc++.h>
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N];
void Metallica()
{
	int n=read(),x=read(),sum=0;
	for (int i=1;i<=n;i++) sum+=a[i]=read();
	if (sum%x) return print(n);
	int l=1,r=n;
	while (l<=n&&a[l]%x==0) l++;
	while (r>=1&&a[r]%x==0) r--;
	if (l>n) return puts("-1"),void();
	print(max(n-l,r-1));
}

signed main()
{
	int T=read();
	while (T--) Metallica();
	
	return 0;
}