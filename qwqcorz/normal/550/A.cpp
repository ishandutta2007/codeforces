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
char c[N];
int a[N],b[N],l=0,r=0;
bool check()
{
	if (!l||!r) return 0;
	if (abs(a[l]-b[1])>=2) return 1;
	if (abs(b[r]-a[1])>=2) return 1;
	return 0;
}

signed main()
{
	scanf("%s",c+1);
	int n=strlen(c+1);
	for (int i=1;i<n;i++)
	if (c[i]=='A'&&c[i+1]=='B')
	a[++l]=i;
	for (int i=1;i<n;i++)
	if (c[i]=='B'&&c[i+1]=='A')
	b[++r]=i;
	puts(check()?"YES":"NO");

	return 0;
}