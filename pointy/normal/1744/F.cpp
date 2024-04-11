// Author: Little09
// Problem: F. MEX vs MED
// Contest: Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/F
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
int a[N],p[N];
inline ll S(ll l,ll r)
{
	return (r-l+1)*(l+r)/2;
}
ll work(ll x,ll y,ll z)
{
	ll res=0;
	x=min(x,z),y=min(y,z)+1;
	z++;
	if (y<=z-x) return y*(x+1);
	if (y>=z) return S(z-x,z);
	return S(z-x,y)+(z-y)*y;
}

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) a[i]++,p[a[i]]=i;
	int l=n+1,r=0;
	ll ans=1;
	for (int i=1;i<n;i++)
	{
		l=min(l,p[i]),r=max(r,p[i]);
		if (p[i+1]>=l&&p[i+1]<=r) continue;
		int len=2*i;
		if (r-l+1>len) continue;
		if (p[i+1]<l) ans+=work(l-p[i+1]-1,n-r,len-(r-l+1));
		else ans+=work(l-1,p[i+1]-r-1,len-(r-l+1));
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