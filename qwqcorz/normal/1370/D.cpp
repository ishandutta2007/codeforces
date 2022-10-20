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
bool b[N];
int a[N],n,k;
bool check(int x)
{
	bool f=1;
	int ans=0,cnt=0;
	for (int i=1;i<=n;i++) b[i]=a[i]<=x;
	b[0]=b[1]^1;
	for (int i=1;i<=n;i++)
	if (b[i]==b[i-1]) cnt++;
	else
	if (b[i-1])
	{
		if (f) ans+=cnt;
		  else ans+=cnt-!(cnt&1);
		f=0;
		cnt=1;
	}
	else
	{
		if (cnt)
		{
			ans++;
			f=0;
		}
		cnt=1;
	}
	if (b[n]) ans+=cnt;
		 else ans++;
	return ans>=k;
}

int main()
{
	n=read();
	k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int l=1,r=1e9;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
				   else l=mid+1;
	}
	print(l);

	return 0;
}