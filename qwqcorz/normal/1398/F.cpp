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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
char a[N];
int pre0[N],pre1[N],pre[N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read();
	scanf("%s",a+1);
	for (int i=1;i<=n;i++) pre0[i]=a[i]=='0'?0:pre0[i-1]+1;
	for (int i=1;i<=n;i++) pre1[i]=a[i]=='1'?0:pre1[i-1]+1;
	for (int i=1;i<=n;i++) pre[i]=max(a[i]!='1'?pre1[i]:0,a[i]!='0'?pre0[i]:0);
	for (int x=1;x<=n;x++)
	{
		int ans=0;
		for (int i=0;i+x<=n;)
		if (pre[i+x]>=x) ans++,i+=x;
					else i=i+x-pre[i+x];
		print(ans," \n"[x==n]);
	}
	
	return 0;
}