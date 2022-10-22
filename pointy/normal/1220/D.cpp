// Author: Little09
// Problem: D. Alex and Julian
// Contest: Codeforces Round #586 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1220/problem/D
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
 
const int N=200005;
int n,m; 
ll a[N];
vector<ll>b[N];
ll lb(ll x)
{
	int cnt=0;
	while (x%2==0) x/=2,cnt++;
	return cnt;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) b[lb(a[i])].push_back(a[i]);
	int ans=0,u=-1;
	for (int i=0;i<=100;i++) 
	{
		if (u==-1||ans<b[i].size()) u=i,ans=b[i].size(); 
	}
	cout << n-ans << endl;
	for (int i=0;i<=100;i++)
	{
		if (i==u) continue;
		for (ll j:b[i]) cout << j << " ";
	}
	return 0;
}