#include <bits/stdc++.h>
using namespace std;
int n,k; 
const int N=505;
int dp[N],tr[N],ans;
void print(int l,int r,int p)
{
	for (int i=1;i<=n;i++)
	{
		if (i>=l&&i<=r) continue;
		cout << i << " ";
		p--;
		if (!p) return;
	}
}
void work(int x)
{
	if (x==0) return;
	if (tr[x]==k)
	{
		cout << "? ";
		for (int i=1;i<=k;i++) cout << x-i+1 << " ";
		cout << endl;
		fflush(stdout);
		int u;
		cin >> u;
		ans^=u;
	}
	else
	{
		cout << "? ";
		for (int i=1;i<=tr[x]/2;i++) cout << x-i+1 << " ";
		print(x-tr[x]+1,x,k-tr[x]/2);
		cout << endl;
		fflush(stdout);
		int u;
		cin >> u;
		ans^=u;
		cout << "? ";
		for (int i=1;i<=tr[x]/2;i++) cout << x-tr[x]/2-i+1 << " ";
		print(x-tr[x]+1,x,k-tr[x]/2);
		cout << endl;
		fflush(stdout);
		cin >> u;
		ans^=u;
	}
	work(x-tr[x]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	memset(dp,20,sizeof(dp));
	dp[0]=0;
	for (int i=1;i<=n;i++)
	{
		if (i>=k)
		{
			if (dp[i]>dp[i-k]+1) dp[i]=dp[i-k]+1,tr[i]=k;
		}
		for (int j=2;j<2*k;j+=2)
		{
			if (i>=j&&j/2+k<=n) if (dp[i]>dp[i-j]+2) dp[i]=dp[i-j]+2,tr[i]=j;
		}
	}
	if (dp[n]==336860180)
	{
		cout << -1;
		return 0;
	}
	work(n);
	cout << "! " << ans << endl;
	fflush(stdout);
	return 0;
}