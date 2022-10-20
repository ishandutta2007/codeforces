#include<bits/stdc++.h>
#define ll long long
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
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
char a[N];
int pre[N],suf[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	scanf("%s",a+1);
	int n=strlen(a+1); ll ans=0;
	for (int i=2;i<=n;i++) pre[i]=pre[i-1]+(a[i]=='v'&&a[i-1]=='v');
	for (int i=n-1;i>=1;i--) suf[i]=suf[i+1]+(a[i]=='v'&&a[i+1]=='v');
	for (int i=1;i<=n;i++) if (a[i]=='o') ans+=1LL*pre[i-1]*suf[i+1];
	print(ans);
	
	return 0;
}