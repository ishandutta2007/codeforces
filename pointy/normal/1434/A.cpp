// Author: Little09
// Problem: A. Perform Easily
// Contest: Codeforces Round #679 (Div. 1, based on Technocup 2021 Elimination Round 1)
// URL: https://codeforces.com/contest/1434/problem/A
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

const int N=600005;
int n,m; 
int a[7],b[N];
int cnt;
struct point
{
	ll x,col;
}c[N];
bool cmp(point x,point y)
{
	return x.x<y.x;
}
multiset<ll>s;
ll d[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i=1;i<=6;i++) cin >> a[i];
	cin >> n;
	for (int i=1;i<=n;i++) cin >> b[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=6;j++)
		{
			c[++cnt].x=b[i]-a[j],c[cnt].col=i;
		}
	}
	sort(c+1,c+cnt+1,cmp);
	ll ans=inf;
	for (int i=1;i<=n;i++) s.insert(-inf),d[i]=-inf;
	for (int i=1;i<=cnt;i++)
	{
		s.erase(s.find(d[c[i].col]));
		d[c[i].col]=i;
		s.insert(d[c[i].col]);
		if (*s.begin()<0) continue;
		ans=min(ans,c[i].x-c[*s.begin()].x);
	}
	cout << ans;
	return 0;
}