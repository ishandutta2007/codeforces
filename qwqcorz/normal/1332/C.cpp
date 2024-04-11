#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int WCR=2333;

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
int cnt[26],a[N];

int main()
{
	int t=read();
	while (t--)
	{
		int n=read(),k=read(),ans=0;
		for (int i=1;i<=n;i++)
		{
			char c=getchar();
			while (c<'a'||'z'<c) c=getchar();
			a[i]=c-'a';
		}
		for (int i=1;i<=k/2;i++)
		{
			int Max=0;
			for (int j=0;j<26;j++) cnt[j]=0;
			for (int j=i;j<=n;j+=k) cnt[a[j]]++;
			for (int j=k-i+1;j<=n;j+=k) cnt[a[j]]++;
			for (int j=0;j<26;j++) Max=max(Max,cnt[j]);
			ans+=2*(n/k)-Max;
		}
		if (k&1)
		{
			int Max=0;
			for (int j=0;j<26;j++) cnt[j]=0;
			for (int j=k/2+1;j<=n;j+=k) cnt[a[j]]++;
			for (int j=0;j<26;j++) Max=max(Max,cnt[j]);
			ans+=n/k-Max;
		}
		print(ans);
	}

	return 0;
}