#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int inf=1ll<<60;

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
int pre[N],tot;
bool a[N];
bool check(int n,int i)
{
	tot=0;
	for (int j=0;j<n;j+=i,tot++)
	if (a[j])
	{
		if (j-pre[j]>=i) return 0;
		j=pre[j];
		if (j<0) return 0;
	}
	return 1;
}

signed main()
{
	memset(a,0,sizeof(a));
	int n=read(),m=read(),k=read(),ans=inf;
	for (int i=1;i<=m;i++) a[read()]=1;
	if (a[0]) pre[0]=-1;
		 else pre[0]=0;
	for (int i=1;i<=n;i++)
	if (a[i]==0) pre[i]=i;
			else pre[i]=pre[i-1];
	for (int i=1;i<=k;i++)
	{
		int x=read();
		if (check(n,i))
		ans=min(ans,tot*x);
	}
	print(ans==inf?-1:ans);

	return 0;
}