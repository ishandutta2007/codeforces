#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int dp[N],tag[N],s[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		int n=read();
		for (int i=1;i<=n;i++) tag[i]=read();
		for (int i=1;i<=n;i++) s[i]=read();
		for (int i=1;i<=n;i++) dp[i]=0;
		for (int i=2;i<=n;i++)
		for (int j=i-1;j>=1;j--)
		if (tag[i]!=tag[j])
		{
			int ti=dp[i],tj=dp[j],val=abs(s[i]-s[j]);
			dp[i]=max(dp[i],tj+val);
			dp[j]=max(dp[j],ti+val);
		}
		print(*max_element(dp+1,dp+1+n));
	}
	
	return 0;
}