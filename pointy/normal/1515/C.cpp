// Author: Little09
// Problem: C. Phoenix and Towers
// Contest: Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/C
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,k; 
int a[N];
struct point
{
	int x,id;
	bool operator < (const point & o) const
	{
		return x>o.x;
	}
};
priority_queue<point>q;


void work()
{
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	while (!q.empty()) q.pop();
	printYES;
	for (int i=1;i<=m;i++) q.push((point){0,i});
	for (int i=1;i<=n;i++)
	{
		point u=q.top();
		q.pop();
		cout << u.id << " ";
		u.x+=a[i];
		q.push(u);
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