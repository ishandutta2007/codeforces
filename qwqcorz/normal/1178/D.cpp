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
bool check(int n)
{
	for (int i=2;i*i<=n;i++)
	if (n%i==0) return 0;
	return 1;
}
vector<pair<int,int>>e;

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m;
	if (n==4) return puts("5\n1 2\n1 3\n2 3\n2 4\n3 4"),0;
	for (m=n;!check(m);m++);
	for (int i=1;i<=n;i++) e.push_back(make_pair(i,i%n+1));
	for (int i=1;i<=m-n;i++) e.push_back(make_pair(i,n/2+i));
	print(e.size());
	for (auto i:e) print(i.first,' '),print(i.second);
	
	return 0;
}