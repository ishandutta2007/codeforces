// Author: Little09
// Problem: C. Monoblock
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
ll ans;
ll b[N];

void update(int x)
{
	if (x==0||x==n) return;
	ans-=b[x]*(n-x)*x;
	b[x]=(a[x]!=a[x+1]);
	ans+=b[x]*(n-x)*x;
}

void work()
{
	cin >> n >> m;
	ans=1ll*(n+1)*n/2;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) b[i]=0;
	for (int i=1;i<=n;i++) update(i);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		a[x]=y;
		update(x),update(x-1);
		cout << ans << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	while (T--) work();
	return 0;
}