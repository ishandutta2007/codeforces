#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;

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
bool check(char x)
{
	if (x=='a') return 1;
	if (x=='e') return 1;
	if (x=='i') return 1;
	if (x=='o') return 1;
	if (x=='u') return 1;
	return 0;
}
char a[N];

signed main()
{
	scanf("%s",a+1);
	int n=strlen(a+1);
	for (int i=1;i<n;i++)
	if (!check(a[i])&&a[i]!='n')
	if (!check(a[i+1]))
	return puts("NO"),0;
	if (!check(a[n])&&a[n]!='n')
	return puts("NO"),0;
	puts("YES");

	return 0;
}