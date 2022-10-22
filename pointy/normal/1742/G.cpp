// Author: Little09
// Problem: G. Orray
// Contest: Codeforces Round #827 (Div. 4)
// URL: https://codeforces.com/contest/1742/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,bas,inf=(1<<30)-1; 
int a[N];
bool cmp(int x,int y)
{
	return (x&bas)>(y&bas);
}

void work()
{
	cin >> n;
	bas=(1<<30)-1;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		int x=(a[i]&bas);
		cout << a[i] << ' ';
		a[i]=0;
		for (;x;x^=lowbit(x))
		{
			bas^=lowbit(x);
			sort(a+i+1,a+n+1,cmp);
		}
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