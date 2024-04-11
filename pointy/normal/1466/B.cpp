// Author: Little09
// Problem: B. Last minute enhancements
// Contest: Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/B
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
multiset<int>s;
map<int,int>q;

void work()
{
	cin >> n;
	s.clear();
	q.clear();
	for (int i=1;i<=n;i++) 
	{
		int x;
		cin >> x;
		s.insert(x);
	}
	int ans=0;
	while (!s.empty())
	{
		int u=*s.begin();
		s.erase(s.find(u));
		if (q[u]==0) ans++,q[u]=1;
		else if (q[u+1]==0) ans++,q[u+1]=1;
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