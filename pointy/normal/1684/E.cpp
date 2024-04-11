// Author: Little09
// Problem: E. MEX vs DIFF
// Contest: Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/E
// Memory Limit: 256 MB
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

const int N=500005;
int n,m; 
int a[N];
int b[N],cnt,c[N];
map<int,int>q;

void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	q.clear();
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		q[a[i]]++;
		if (q[a[i]]==1) b[++cnt]=a[i];
	}
	if (m==0)
	{
		for (int i=0;;i++)
		{
			if (q[i]==0) 
			{
				cout << cnt-i << endl;
				return;
			}
		}
	}
	int num=0,tot=0,ans=0;
	for (int i=0;;i++)
	{
		if (q[i]==0) 
		{
			num++;
			if (num>m)
			{
				num--;
				ans=i;
				break;
			}
		}
		else tot+=q[i];
	}
	tot=n-tot;
	if (tot<=m)
	{
		cout << 0 << endl;
		return;
	}
	int uuu=0;
	for (int i=1;i<=cnt;i++)
	{
		if (b[i]>=ans)
		{
			c[++uuu]=q[b[i]];
		}
	}
	sort(c+1,c+uuu+1);
	for (int i=1;i<=uuu;i++)
	{
		if (m>=c[i]) m-=c[i];
		else 
		{
			cout << uuu-i+1 << endl;
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}