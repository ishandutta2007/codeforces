#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=(1<<24)+100;
int n,m,T; 
int a[N],dp[N];
int ans;
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		int u=0;
		for (int j=1;j<=3;j++)
		{
			char x=readchar();
			if (x>='y') continue;
			u|=(1<<(x-'a'));
		}
		dp[u]++;
	}
	for (int i=0;i<24;i++)
	{
		for (int j=0;j<(1<<24);j++)
		{
			if (j&(1<<i)) dp[j]+=dp[j^(1<<i)];
		}
	}
	for (int i=0;i<(1<<24);i++) ans=ans^((n-dp[i])*(n-dp[i]));
	cout << ans;
	return 0;
}