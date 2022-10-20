#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;

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
int dp[N][5];

signed main()
{
	int n=1e4,l=1;
	for (int j=1;j<=4;j++)
	for (int i=1;i<=n;i++)
	{
		dp[i][j]=dp[i][j-1];
		int now=i+dp[i][j-1]+1;
		for (int k=1;k<=i;k++)
		{
			if (now>=n)
			{
				dp[i][j]+=(dp[n][j-1]+1)*(i-k+1);
				break;
			}
			dp[i][j]+=dp[now][j-1]+1;
			now+=dp[now][j-1]+1;
		}
	}
	for (int i=4;i>=0;i--)
	{
		vector<int>x;
		int tmp=l;
		for (int j=1;j<=min(l,n);j++)
		{
			tmp+=dp[min(tmp,n)][i];
			if (tmp>10004205361450474) break;
			x.push_back(tmp);
			tmp++;
		}
		print(x.size(),' ');
		for (int i:x) print(i,' ');
		cout<<endl;
		int t=read();
		if (t<0) return 0;
		l=t?x[t-1]+1:l;
	}
	
	return 0;
}