#include<bits/stdc++.h>
using namespace std;
const int N=505;

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
int a[N][N],p[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) p[i]=a[i][i]=read();
	for (int i=1;i<n;i++)
	{
		int j;
		for (j=1;p[j]>1;j++)
		a[i+j][j]=a[i+j-1][j];
		for (;j<=n-i;j++)
		a[i+j][j]=a[i+j][j+1];
		for (j=1;p[j]>1;j++);
		for (;j<=n-i;j++) p[j]=p[j+1];
		for (j=1;j<=n-i+1;j++) p[j]--;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=i;j++) print(a[i][j],j%i?' ':'\n');

	return 0;
}