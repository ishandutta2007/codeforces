#include<bits/stdc++.h>
using namespace std;
const int N=105;

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
vector<int>ans;
int a[N];

signed main()
{
	int T=read();
	while (T--)
	{
		bool flag=1;
		ans.clear();
		memset(a,0,sizeof(a));
		int n=read(),x=read(),sum=0;
		for (int i=1;i<=n;i++) a[read()]++;
		for (int i=1;i<=n;i++)
		{
			int Max=0;
			for (int j=1;j<=100;j++) if (a[j]&&sum+j!=x) if (a[j]>a[Max]) Max=j;
			if (!Max)
			{
				flag=0;
				puts("NO");
				break;
			}
			else
			{
				sum+=Max;
				a[Max]--;
				ans.push_back(Max);
			}
		}
		if (flag)
		{
			puts("YES");
			for (int i:ans) print(i,' ');
			puts("");
		}
	}

	return 0;
}