#include<bits/stdc++.h>
using namespace std;
const int N=5005;

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
int n,k;
char a[N],b[N],ans[N];
bool check(char *a,char *b)
{
	for (int i=1;i<=n;i++)
	{
		if (a[i]<b[i]) return 0;
		if (a[i]>b[i]) return 1;
	}
	return 0;
}

int main()
{
	int T=read();
	while (T--)
	{
		k=1;
		n=read();
		for (int i=1;i<=n;i++)
		{
			char c=getchar();
			while (c<'a'||'z'<c) c=getchar();
			ans[i]=a[i]=c;
		}
		for (int i=2;i<=n;i++)
		{
			int cnt=0;
			for (int j=i;j<=n;j++) b[++cnt]=a[j];
			if ((n-i)%2) for (int j=1;j<=i-1;j++) b[++cnt]=a[j];
					else for (int j=i-1;j>=1;j--) b[++cnt]=a[j];
			if (check(ans,b))
			{
				for (int j=1;j<=n;j++) ans[j]=b[j];
				k=i;
			}
		}
		for (int i=1;i<=n;i++) putchar(ans[i]);
		puts("");
		print(k);
	}

	return 0;
}