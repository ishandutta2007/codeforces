#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;

bool get()
{
	char c=getchar();
	while (c<'A'||'Z'<c) c=getchar();
	return c=='B';
}
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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N],b[N];
int first(int n,int k)
{
	for (int i=1;i<=n;i++)
	if (a[i]==a[i+1])
	{
		for (int j=i;j<i+n;j++) a[j-i+1]=a[j+1];
		return i+1;
	}
	k&=1;
	for (int i=1;i<=n;i++) putchar((a[i]^k)?'B':'W');
	exit(0);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),k=read();
	for (int i=1;i<=n;i++) a[i+n]=a[i]=get();
	int m=first(n,k);
	for (int i=2;i<n;i++) b[i]=a[i]!=a[i-1]&&a[i]!=a[i+1];
	for (int i=2;i<n;i++)
	if (b[i])
	{
		int l=i;
		while (b[i+1]) i++;
		int r=i,tmp=k;
		while (l<=r&&tmp)
		{
			a[l]=a[l-1];
			a[r]=a[r+1];
			l++,r--;
			tmp--;
		}
		for (int j=l;j<=r;j++) a[j]=a[j-1]^1;
	}
	for (int i=n-m+2;i<=n;i++) putchar(a[i]?'B':'W');
	for (int i=1;i<=n-m+1;i++) putchar(a[i]?'B':'W');
	
	return 0;
}