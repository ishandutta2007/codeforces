#include<bits/stdc++.h>
using namespace std;
const int N=200;

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
bool a[N];

int main()
{
	int T=read();
	while (T--)
	{
		int n=0;
		char c=getchar();
		while (c!='0'&&c!='1') c=getchar();
		while (c=='0'||c=='1') a[++n]=c-'0',c=getchar();
		int l=1,r=n;
		while (l<=n&&a[l]==0) l++;
		while (r>=1&&a[r]==0) r--;
		if (r==0) print(0);
		else
		{
			int ans=0;
			for (int i=l;i<=r;i++) ans+=!a[i];
			print(ans);
		}
	}

	return 0;
}