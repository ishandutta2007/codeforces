#include<bits/stdc++.h>
#define int long long
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
inline void up(int &x,int y){if (x<y) x=y;}
int a[50];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),ans=0;
	for (int i=0;i<9;i++)
	for (int j=0;j<49;j++)
	up(a[(i*4+j*9)%49],n-i-j+1);
	for (int i=0;i<49;i++) ans+=a[i];
	print(ans);
	
	return 0;
}