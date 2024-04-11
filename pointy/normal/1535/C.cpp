#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=200005;
int n,m,T; 
char a[N];
int dp[N][2],s[N][2];
inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
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
ll ans;
void work()
{
	cin >> a;
	n=strlen(a);
	ans=0;
	for (int i=0;i<n;i++)
	{
		dp[i][0]=dp[i][1]=0;
		s[i][0]=s[i][1]=-1;
	}
	for (int i=0;i<n;i++)
	{
		if (a[i]=='0') 
		{
			if (i%2==0) dp[i][0]=1;
			else dp[i][1]=1;
		}
		else if (a[i]=='1')
		{
			if (i%2==1) dp[i][0]=1;
			else dp[i][1]=1;
		}
	}
	for (int i=0;i<n;i++)
	{
		if (dp[i][0]==1) s[i][0]=i;
		else if (i!=0) s[i][0]=s[i-1][0];
		if (dp[i][1]==1) s[i][1]=i;
		else if (i!=0) s[i][1]=s[i-1][1];
	}
	for (int i=0;i<n;i++)
	{
		if (dp[i][0]==1) 
		{
			int u=s[i][1];
			ll len=i-u;
			ans+=len;
		}
		else if (dp[i][1]==1)
		{
			int u=s[i][0];
			ll len=i-u;
			ans+=len;
		}
		else
		{
			int u=min(s[i][0],s[i][1]);
			ll len=i-u;
			ans+=len;
		}
	}
	cout << ans << endl;
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}