// Author: Little09
// Problem: F. Tokitsukaze and Strange Rectangle
// Contest: Codeforces - Codeforces Round #573 (Div. 2)
// URL: https://codeforces.com/contest/1191/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int n,m; 
int a[N],c[N],b[N],d[N],f[N];
int cntc,cntd;
vector<int>t[N];
ll s[N];

ll tree[N];
inline void add(int x,int k)
{
	for (;x<=cntc;x+=lowbit(x)) tree[x]+=k;
}
inline ll ask(int x)
{
	ll ans=0;
	for (;x;x-=lowbit(x)) ans+=tree[x];
	return ans;
}
ll query(ll x,ll y)
{
	return ask(y)-ask(x-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i] >> b[i];
	for (int i=1;i<=n;i++) c[i]=a[i],d[i]=b[i];
	sort(c+1,c+n+1),sort(d+1,d+n+1);;
	cntc=unique(c+1,c+n+1)-c-1;
	cntd=unique(d+1,d+n+1)-d-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(c+1,c+cntc+1,a[i])-c;
	for (int i=1;i<=n;i++) b[i]=lower_bound(d+1,d+cntd+1,b[i])-d;
	for (int i=1;i<=n;i++) t[b[i]].push_back(a[i]);
	for (int i=1;i<=cntd;i++) sort(t[i].begin(),t[i].end());
	ll ans=0;
	for (int i=cntd;i>=1;i--)
	{
		int las=1;
		for (int j:t[i])
		{
			if (f[j]==0) 
			{
				f[j]=1;
				add(j,1);
			}
		}
		for (int j:t[i])
		{
			ans+=query(las,j)*query(j,cntc);
			las=j+1;
		}
	}
	cout << ans;
	// for (int i=1;i<=n;i++) cout << a[i] << " ";
	// cout << endl;
	// for (int i=1;i<=n;i++) cout << b[i] << " ";
	// cout << endl;
	
	return 0;
}