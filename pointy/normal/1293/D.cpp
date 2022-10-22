// Author: Little09
// Problem: D. Aroma's Search
// Contest: Codeforces Round #614 (Div. 2)
// URL: https://codeforces.com/contest/1293/problem/D
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

const ll inf=10010000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll x[N],y[N];

ll a,b,c,d,e,f,sx,sy,t;
ll work(int l,int r)
{
	ll res=0,tot=0;
	res=abs(sx-x[l])+abs(sy-y[l]);
	if (res>t) return 0;
	tot=1;
	for (int i=l+1;i<=r;i++) 
	{
		res+=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
		if (res>t) return tot;
		tot++;
	}
	ll lasx=x[r],lasy=y[r];
	for (int i=l-1;i>=0;i--) 
	{
		res+=abs(x[i]-lasx)+abs(y[i]-lasy);
		lasx=x[i],lasy=y[i];
		if (res>t) return tot;
		tot++;
	}
	return tot;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b >> c >> d >> e >> f >> sx >> sy >> t;
	int cnt=0;
	x[cnt]=a,y[cnt]=b;
	while (1)
	{
		cnt++;
		x[cnt]=x[cnt-1]*c+e;
		y[cnt]=y[cnt-1]*d+f;
		if (x[cnt]>inf||y[cnt]>inf) break;
	}
	//cout << work(1,2) << endl;
	//for (int i=0;i<=cnt;i++) cout << x[i] << " " << y[i] << endl;
	ll ans=0;
	for (int i=0;i<=cnt;i++)
	{
		for (int j=i;j<=cnt;j++)
		{
			ans=max(ans,work(i,j));
			//if (work(i,j)==4) cout << i << " " << j << endl;
		}
	}
	cout << ans << endl;
	return 0;
}