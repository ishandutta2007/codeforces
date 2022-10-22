// Author: Little09
// Problem: B. Balls of Steel
// Contest: Codeforces Global Round 12
// URL: https://codeforces.com/contest/1450/problem/B
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
int n,m,k; 
int a[N],b[N];

int work(int x)
{
	int res=0;
	for (int i=1;i<=n;i++)
	{
		if (abs(a[i]-a[x])+abs(b[i]-b[x])<=k) res++;
	}
	if (res==n) return 1;
	return -1;
}

void work()
{
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i] >> b[i];
	int ans=-1;
	for (int i=1;i<=n;i++) ans=max(ans,work(i));
	cout << ans << endl;
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