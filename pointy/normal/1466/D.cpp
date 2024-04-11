// Author: Little09
// Problem: D. 13th Labour of Heracles
// Contest: Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
ll a[N],d[N];
vector<int>t[N];
ll c[N],cnt;

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) t[i].clear(),d[i]=0;
	ll res=0;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		t[x].push_back(y),t[y].push_back(x);
		d[x]++,d[y]++;
	}
	for (int i=1;i<=n;i++) res+=a[i];
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=2;j<=d[i];j++) c[++cnt]=a[i];
	}
	sort(c+1,c+cnt+1);
	cout << res << " ";
	for (int i=1;i<n-1;i++) 
	{
		res+=c[cnt+1-i];
		cout << res << " ";
	}
	cout << endl;
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