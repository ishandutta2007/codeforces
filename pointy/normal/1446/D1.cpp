// Author: Little09
// Problem: CF1446D1 Frequency Problem (Easy Version)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1446D1
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=200005;
int n,m; 
int a[N],b[N],c[N],d[N*2];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) b[a[i]]++;
	int u=0,cnt=1;
	for (int i=1;i<=100;i++) 
	{
		if (b[u]<b[i]) u=i,cnt=1;
		else if (b[u]==b[i]) cnt++;
	}
	if (cnt>1)
	{
		cout << n << endl;
		return 0;
	}
	int ans=0;
	for (int i=1;i<=100;i++)
	{
		if (i==u||b[i]==0) continue;
		for (int j=1;j<=n;j++) 
		{
			if (a[j]==u) c[j]=1;
			else if (a[j]==i) c[j]=-1;
			else c[j]=0;
		}
		for (int j=1;j<=n;j++) c[j]+=c[j-1];
		for (int j=0;j<N*2;j++) d[j]=n+1;
		d[N]=0;
		for (int j=1;j<=n;j++)
		{
			d[c[j]+N]=min(d[c[j]+N],j);
			ans=max(ans,j-d[c[j]+N]);
		}
	}
	cout << ans << endl;
	return 0;
}