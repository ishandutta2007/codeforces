#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;

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
int a[N];

signed main()
{
	int T=read();
	while (T--)
	{
		string s="";
		int n=read(),Max=0;
		a[0]=a[n+1]=0;
		for (int i=1;i<=n;i++) Max=max(Max,a[i]=read());
		Max++;
		for (int i=1;i<=Max;i++) s=s+'a';
		cout<<s<<endl;
		for (int i=1;i<=n;i++)
		{
			if (s[a[i]]=='z') s[a[i]]--;
						 else s[a[i]]++;
			cout<<s<<endl;
		}
	}

	return 0;
}