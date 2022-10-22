// Author: Little09
// Problem: C. Tonya and Burenka-179
// Contest: Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
 
const int N=200005,M=200;
int n,m; 
ll a[N],b[N];
int cnt;
vector<ll>t[N];
priority_queue<ll>s[M],p[M];
const int MAXN=N-2;
int v[N],pr[N];
 
void init() 
{
    v[1]=1;
    int cnt=0;
    for (int i=2;i<=MAXN;++i) 
	{
        if (!v[i]) pr[++cnt]=i;
        for (int j=1;j<=cnt&&i*pr[j]<=MAXN;++j) 
		{
            v[i*pr[j]]=1;
            if (i%pr[j]==0) break; 
        }
    }
}
 
void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	// n=196560,m=2e5;
	// for (int i=1;i<=n;i++) a[i]=0;
	cnt=0;
	for (int i=1;i<=sqrt(n);i++)
	{
		if (n%i==0)
		{
			if (v[n/i]==0) b[++cnt]=i;
			if (i*i!=n) if (v[i]==0) b[++cnt]=n/i;
		}
	}
	sort(b+1,b+cnt+1);
	ll res=0;
	for (int i=1;i<=cnt;i++)
	{
		t[i].clear();
		while (!s[i].empty()) s[i].pop();
		while (!p[i].empty()) p[i].pop();
		for (int j=1;j<=b[i];j++) t[i].push_back(0);
		for (int j=1;j<=n;j++) t[i][j%b[i]]+=a[j];
		for (int j=0;j<b[i];j++) s[i].push(t[i][j]*b[i]);
		res=max(res,s[i].top());
	}
	cout << res << endl;
	for (int i=1;i<=m;i++)
	{
		ll x,y;
		cin >> x >> y;
		//x=1,y=rand();
		ll ans=0;
		for (int k=1;k<=cnt;k++)
		{
			p[k].push(t[k][x%b[k]]*b[k]);
			t[k][x%b[k]]+=y-a[x];
			s[k].push(t[k][x%b[k]]*b[k]);
			while (!p[k].empty()&&s[k].top()==p[k].top()) s[k].pop(),p[k].pop();
			ans=max(ans,s[k].top());
		}
		a[x]=y;
		cout << ans << endl;
	}
}
 
int main()
{
	init();
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}