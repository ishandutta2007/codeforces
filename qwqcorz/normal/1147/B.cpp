#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
int siz[N];
vector<int>a[N];
bool check(int n,int k)
{
//	print(k,':');
	for (int i=1;i<=n;i++)
	if (i*2!=n)
	for (int j=0;j<siz[i];j++)
	{
		int pos=lower_bound(a[i].begin(),a[i].end(),a[i][j]+k)-a[i].begin();
//		print(a[i][pos]);
		if (pos>=a[i].size()||a[i][pos]!=a[i][j]+k) return 0;
	}
	return 1;
}
void ins(int l,int r,int n)
{
	if (r<l) r+=n;
	a[r-l].push_back(l);
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read();
		ins(l,r,n);
		ins(r,l,n);
	}
	for (int i=1;i<=n;i++) sort(a[i].begin(),a[i].end());
	for (int i=1;i<=n;i++)
	{
		siz[i]=a[i].size();
		for (int j=0;j<siz[i];j++) a[i].push_back(a[i][j]+n);
		if (i*2==n) for (int j=0;j<siz[i];j++) a[i].push_back(a[i][j]+i);
	}
	for (int i=1;i<=n;i++) sort(a[i].begin(),a[i].end());
//	for (int i=1;i<=n;i++,puts(""))
//		for (int j=0;j<a[i].size();j++) print(a[i][j],' ');
	int nn=n;
	for (int k=2;k<=sqrt(nn);k++)
	if (nn%k==0)
	{
		while (nn%k==0) nn/=k;
		if (check(n,n/k))
		return puts("Yes"),0;
	}
	if (nn>1)
	if (check(n,n/nn))
	return puts("Yes"),0;
	puts("No");

	return 0;
}