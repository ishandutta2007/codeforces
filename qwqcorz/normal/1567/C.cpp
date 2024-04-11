#include<bits/stdc++.h>
using namespace std;

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
void GunRose()
{
	int n=read(),a[2]={},pw=1;
	for (int i=0;n;pw*=i?10:1,i^=1) a[i]+=pw*(n%10),n/=10;
	print((a[0]+1)*(a[1]+1)-2);
}

signed main()
{
	int T=read();
	while (T--) GunRose();
	
	return 0;
}