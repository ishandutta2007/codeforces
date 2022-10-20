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
int x[N],a[N],st[N],top,l[N],r[N];
int find(int p)
{
	int L=0,R=top;
	while (L<=R)
	{
		int mid=(L+R)/2;
		if (a[st[mid]]+x[l[st[mid]]]>=p) L=mid+1;
									else R=mid-1;
	}
	return R;
}
int solve(int n)
{
	st[top=0]=0;
	for (int i=1;i<=n+1;i++)
	{
		while (top&&x[i]-x[st[top-1]]>a[st[top]]) top--;
		l[i]=st[top];
		st[++top]=i;
	}
	if (top>1) return 0;
	st[top=0]=n+1;
	for (int i=n;i>=0;i--)
	{
		while (top&&x[st[top-1]]-x[i]>a[st[top]]) top--;
		r[i]=st[top];
		st[++top]=i;
	}
	st[top=0]=0;
	int ans=x[n+1]-x[0];
	for (int i=1;i<=n;i++)
	{
		int p=x[r[i]]-a[i];
		if (p<x[i])
		{
			int pos=find(p);
			ans=min(ans,x[i]-x[st[pos]]);
		}
		ans=min(ans,x[r[i]]-x[l[i]]);
		if (x[i]-x[l[i]]<a[i])
		{
			while (top&&a[st[top]]+x[l[st[top]]]<=a[i]+x[l[i]]) top--;
			st[++top]=i;
		}
	}
	for (int i=0,tmp=x[n+1];i<=n+1;i++) x[i]=tmp-x[i];
	reverse(x,x+n+2);
	reverse(a,a+n+2);
	return ans;
}

signed main()
{
	int n=read();
	for (int i=0;i<=n+1;i++) x[i]=read();
	for (int i=1;i<=n;i++) a[i]=min(read()*2,(int)1e9);
	a[0]=a[n+1]=1e9;
	int ans=solve(n);
	ans=min(ans,solve(n));
	write(ans/2);
	if (ans&1) cout<<".5";
	
	return 0;
}