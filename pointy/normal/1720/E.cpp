// Author: Little09
// Problem: E. Misha and Paintings
// Contest: Codeforces Round #815 (Div. 2)
// URL: https://codeforces.com/contest/1720/problem/E
// Memory Limit: 256 MB
// Time Limit: 3500 ms
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

const int N=505;
int n,m; 
int a[N][N],s[N][N];
int c[N*N];
int d[N*N][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n*n;i++) d[i][0]=d[i][2]=n+1,d[i][1]=d[i][3]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin >> a[i][j];
			d[a[i][j]][0]=min(d[a[i][j]][0],i);
			d[a[i][j]][1]=max(d[a[i][j]][1],i);
			d[a[i][j]][2]=min(d[a[i][j]][2],j);
			d[a[i][j]][3]=max(d[a[i][j]][3],j);
			c[a[i][j]]=1;
		}
	}
	int cnt=0;
	for (int i=1;i<=n*n;i++) cnt+=c[i];
	if (m>=cnt)
	{
		cout << m-cnt << endl;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		mem(s);
		for (int j=1;j<=n*n;j++)
		{
			if (d[j][0]==n+1) continue;
			int x1=max(d[j][1]-i+1,1),x2=d[j][0];
			int y1=max(d[j][3]-i+1,1),y2=d[j][2];
			if (x1>x2||y1>y2) continue;
			//if (i==1) cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
			s[x1][y1]++,s[x1][y2+1]--,s[x2+1][y1]--,s[x2+1][y2+1]++;
		}
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=n;k++)
			{
				s[j][k]=s[j][k]+s[j-1][k]+s[j][k-1]-s[j-1][k-1];
			}
		}
		for (int j=1;j<=n-i+1;j++)
		{
			for (int k=1;k<=n-i+1;k++)
			{
				if (s[j][k]==cnt-m||s[j][k]==cnt-m+1)
				{
					cout << 1 << endl;
					return 0;
				}
			}
		}
	}
	cout << 2 << endl;
	return 0;
}