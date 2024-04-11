// Author: Little09
// Problem: E1. Divisible Numbers (easy version)
// Contest: Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/E1
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
ll a,b,c,d,s;
ll f[N][2],cnt;
map<ll,ll>q;
bool flag=0;

void dfs(ll x,ll y)
{
	if (x==cnt+1)
	{
		if (flag) return;
		ll j=y;
			ll k=s/j;
			if (c/j!=(a)/j&&d/k!=(b)/k)
			{
				cout << c/j*j << " " << d/k*k << endl;
				flag=1;
				return;
			}
			if (c/k!=(a)/k&&d/j!=b/j)
			{
				cout << c/k*k << " " << d/j*j << endl;
				flag=1;
				return;
			}
		return;
	}
	for (int i=0;i<=f[x][1];i++)
	{
		dfs(x+1,y);
		if (flag) return;
		y*=f[x][0];
	}
}

void work()
{
	cin >> a >> b >> c >> d;
	if (c>=a*2&&d>=b*2)
	{
		cout << a*2 << " " << b*2 << endl;
		return;
	}
	q.clear();
	ll x=a;
	for (ll i=2;i<=sqrt(x);i++) 
	{
		while (x%i==0)
		{
			q[i]++;
			x/=i;
		}
	}
	if (x>1) q[x]++;
	x=b;
	for (ll i=2;i<=sqrt(x);i++) 
	{
		while (x%i==0)
		{
			q[i]++;
			x/=i;
		}
	}
	if (x>1) q[x]++;
	cnt=0;
	for (map<ll,ll>::iterator it=q.begin();it!=q.end();it++) f[++cnt][0]=it->first,f[cnt][1]=it->second;
	// for (int i=1;i<=cnt;i++) cout << f[i][0] << " " << f[i][1] << endl;
	// cout << endl;
	// return;
	flag=0,s=a*b;
	dfs(1,1);
		
	if (flag==0) cout << "-1 -1\n";
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