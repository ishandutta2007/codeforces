// Author: Little09
// Problem: E1. LCM Sum (easy version)
// Contest: Codeforces Round #813 (Div. 2)
// URL: https://codeforces.com/contest/1712/problem/E1
// Memory Limit: 512 MB
// Time Limit: 3500 ms
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

const int N=400005;
int n,m;
ll lcm(ll x,ll y)
{
	return x*y/__gcd(x,y);
}
ll c[N],d[N],s[N];
vector<int>t[N];
struct point
{
	int id,l,r;
}b[N];
ll res[N];
vector<point>q;
bool cmp(point x,point y)
{
	return x.l>y.l;
}
void work()
{
	ll l,r,len;
	cin >> l >> r;
	len=r-l+1;
	ll ans=len*(len-1)*(len-2)/6;
	for (int i=l;i<=r;i++)
	{
		int cnt=0;
		ll op=t[i].size()-(lower_bound(t[i].begin(),t[i].end(),l)-t[i].begin());
		ans-=op*(op-1)/2;
		if (i%6==0)
		{
			if (i/2>=l) ans--;
		}
		if (i%15==0)
		{
			if (i*2/5>=l) ans--;
		}
	}
	cout << ans << endl;
}

ll tree[N][2],a[N];
inline void add(int x,ll k,int tp)
{
	for (;x<=200000;x+=lowbit(x)) tree[x][tp]+=k;
}
inline ll ask(int x,int tp)
{
	ll ans=0;
	for (;x;x-=lowbit(x)) ans+=tree[x][tp];
	return ans;
}
void update(int x)
{
	for (int i=2;i*x<=200000;i++)
	{
		ll tmp=a[i*x];
		add(i*x,2*tmp+1,1);
		add(i*x,1,0);
		a[i*x]++;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i=1;i<=200000;i++)
	{
		for (int j=2;i*j<=200000;j++)
		{
			s[i]++;
		}
	}
	for (int i=1;i<=200000;i++) s[i]+=s[i-1];
	int m;
	cin >> m;
	for (int i=1;i<=m;i++)
	{
		b[i].id=i;
		cin >> b[i].l >> b[i].r;
	}
	sort(b+1,b+m+1,cmp);
	int tot=200000;
	for (int i=1;i<=m;i++)
	{
		while (tot>=b[i].l)
		{
			update(tot);
			tot--;
		}
		int l=b[i].l,r=b[i].r;
		ll len=r-l+1;
		ll ans=len*(len-1)*(len-2)/3;
		ans-=ask(b[i].r,1)-ask(b[i].r,0)-ask(b[i].l-1,1)+ask(b[i].l-1,0);
		ll pp=0;
		if (l*2<=r) pp+=r/6-(l*2-1)/6;
		if (l*5/2<=r) pp+=r/15-(l*5/2-1)/15;
		ans-=pp*2;
		// for (int _i=l;_i<=r;_i++)
		// {
			// int cnt=0;
			// if (_i%6==0)
			// {
				// if (_i>=l*2) ans-=2;
			// }
			// if (_i%15==0)
			// {
				// if (_i>=l*5/2) ans-=2;
			// }
		// }
		res[b[i].id]=ans/2;
	}
	for (int i=1;i<=m;i++) cout << res[i] << endl;
	return 0;
}