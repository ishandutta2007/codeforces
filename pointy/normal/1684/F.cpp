// Author: Little09
// Problem: F. Diverse Segments
// Contest: Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/F
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,sum; 
int a[N],s[N],c[N];
int p[N],h[N];
map<int,int>tmp;
int col;
vector<int>b[N];
int g[N];
vector<int>f[N];
void add(int x,int y)
{
	sum++;
	g[x]++;
	f[y].push_back(x);
}
multiset<int>se;
void work()
{
	cin >> n >> m;
	sum=0;
	tmp.clear();
	col=0;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++)
	{
		g[i]=0;
		f[i].clear();
		if (tmp[a[i]]==0) tmp[a[i]]=++col;
		a[i]=tmp[a[i]];
	}
	for (int i=1;i<=n;i++) c[i]=0,p[i]=0;
	for (int i=n;i>=1;i--)
	{
		if (p[a[i]]==0) s[i]=n+1;
		else s[i]=p[a[i]];
		p[a[i]]=i;
	}
	s[n+1]=n+1;
	for (int i=1;i<=n;i++) b[i].clear();
	for (int i=1;i<=m;i++)
	{
		int l,r;
		cin >> l >> r;
		b[l].push_back(r);
	}
	for (int i=1;i<=n;i++) b[i].push_back(i);
	int mx=0;
	for (int i=1;i<=n;i++)
	{
		for (int j:b[i]) mx=max(mx,j);
		int u=s[i],v=s[u];
		if (v<=mx) c[u]=1;
	}
	int l=n+1,r=0;
	for (int i=1;i<=n;i++)
	{
		if (c[i]==1) r=max(r,i),l=min(l,i);
	}
	for (int i=l;i<=r;i++) c[i]=1;
	// cout << l << " " << r << endl << endl;
	mx=0;
	for (int i=1;i<=n;i++) h[i]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j:b[i])
		{
			while (mx<j)
			{
				mx++;
				h[a[mx]]=mx;
			}
		}
		if (c[i]) continue;
		int u=h[a[i]];
		if (i!=u) add(i,u);
	}
	if (sum==0)
	{
		if (r==0) cout << 0 << endl;
		else cout << r-l+1 << endl;
		return;
	}
	if (r!=0) sum+=r-l+1;
	int ans=n,uu=0;
	se.clear();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=g[i];j++) se.insert(i),uu++;
		if (c[i]) se.insert(i),uu++;
		for (int j:f[i]) 
		{
			se.erase(se.find(j));
			se.insert(i);
		}
		if (uu==sum) ans=min(ans,i-*se.begin()+1);
		//cout << "11c " << *se.begin() << endl;
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