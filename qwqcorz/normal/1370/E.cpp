#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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
bool a[N],b[N];
bool get()
{
	char c=getchar();
	while (c<'0'||'1'<c) c=getchar();
	return c-'0';
}
int cnt1=0,cnt2=0;

int main()
{
	int n=read();
	for (int i=1;i<=n;i++) cnt1+=a[i]=get();
	for (int i=1;i<=n;i++) cnt2+=b[i]=get();
	if (cnt1!=cnt2) return puts("-1"),0;
	int ans=0,now=0;
	for (int i=1;i<=n;i++)
	if (a[i]!=b[i])
	ans=max(ans,now=max(now+(a[i]?1:-1),0));
	now=0;
	for (int i=1;i<=n;i++)
	if (a[i]!=b[i])
	ans=max(ans,now=max(now+(b[i]?1:-1),0));
	print(ans);

	return 0;
}