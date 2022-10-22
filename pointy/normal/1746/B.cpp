// Author: Little09
// Problem: B. Rebellion
// Contest: Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],s[N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int flag=0;
	for (int i=1;i<n;i++) if (a[i]>a[i+1]) flag=1;
	if (flag==0)
	{
		cout << 0 << endl;
		return;
	}
	int ans=n;
	for (int i=1;i<=n;i++)
	{
		int x=s[i],y=(n-i-s[n]+s[i]);
		if (x>=y) ans=min(ans,x);
	}
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