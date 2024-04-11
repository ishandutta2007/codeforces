#include<bits/stdc++.h>
using namespace std;
const int N=205;

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
vector<int>ans;
char a[N];
void flip(char &a)
{
	if (a=='W') a='B';
		   else a='W';
}
void check(int n,char c)
{
	for (int i=1;i<n;i++)
	if (a[i]!=c) ans.push_back(i),flip(a[i]),flip(a[i+1]);
	if (a[n]!=c) return;
	print(ans.size());
	for (int i:ans) print(i,' ');
	exit(0);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	scanf("%s",a+1);
	check(n,'B');
	check(n,'W');
	puts("-1");
	
	return 0;
}