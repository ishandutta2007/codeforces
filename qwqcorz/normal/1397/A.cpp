#include<bits/stdc++.h>
using namespace std;

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
string s;
int cnt[100];

int main()
{
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=0;i<=99;i++) cnt[i]=0;
		for (int i=1;i<=n;i++)
		{
			cin>>s;
			int m=s.length();
			for (int j=0;j<m;j++) cnt[s[j]-'a']++;
		}
		bool flag=1;
		for (int i=0;i<=26;i++)
		if (cnt[i]%n!=0)
		{
			flag=0;
			break;
		}
		if (flag) puts("YES");
			 else puts("NO");
	}

	return 0;
}