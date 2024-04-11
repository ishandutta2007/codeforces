#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1e3;
const int M=1e6+1e3;

inline int read()
{
    int s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
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
int a[N],t[M];

int main()
{
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),Min=read(),cnt=0;
		for (int i=1;i<=Min;i++)
		{
			a[i]=read();
			if (t[a[i]]==0) cnt++;
			t[a[i]]++;
		}
		int ans=cnt;
		for (int i=Min+1;i<=n;i++)
		{
			a[i]=read();
			if (t[a[i]]==0) cnt++;
			t[a[i]]++;
			t[a[i-Min]]--;
			if (t[a[i-Min]]==0) cnt--;
			ans=min(ans,cnt);
		}
		for (int i=1;i<=n;i++) t[a[i]]=0;
		write(ans);
		putchar('\n');
	}

	return 0;
}