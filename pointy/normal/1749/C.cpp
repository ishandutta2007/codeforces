// Author: Little09
// Problem: C. Number Game
// Contest: Educational Codeforces Round 138 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1749/problem/C
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

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];

multiset<int>s;

bool check(int x)
{
	s.clear();
	for (int i=1;i<=n;i++) s.insert(a[i]);
	for (int i=x;i>=1;i--)
	{
		if (s.empty()) return 0;
		auto u=s.upper_bound(i);
		if (u==s.begin()) return 0;
		u--;
		s.erase(u);
		if (s.empty()) continue;
		int v=*s.begin();
		s.erase(s.begin());
		v+=i;
		s.insert(v);
	}
	return 1;
}

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (check(i)) ans=i;
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