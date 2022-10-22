// Author: Little09
// Problem: F. Kazaee
// Contest: Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) (x&(-x))

const int N=600005;
int n,m; 
int a[N],b[N],cnt,q[N][4];
mt19937 rnd(time(0));
int c[N],d[N];
int tree[N],ans[N];
inline void add(int x,int k)
{
	for (;x<=n;x+=lowbit(x)) tree[x]+=k;
}
inline int ask(int x)
{
	int ans=0;
	for (;x;x-=lowbit(x)) ans+=tree[x];
	return ans;
}
void update(int x,int k)
{
	if (d[x]==k) return;
	add(x,k-d[x]);
	d[x]=k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=m;i++) 
	{
		cin >> q[i][0] >> q[i][1] >> q[i][2];
		if (q[i][0]==2) cin >> q[i][3];
	}
	for (int i=1;i<=n;i++) b[++cnt]=a[i];
	for (int i=1;i<=m;i++) if (q[i][0]==1) b[++cnt]=q[i][2];
	sort(b+1,b+cnt+1);
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
	for (int i=1;i<=m;i++) if (q[i][0]==1) q[i][2]=lower_bound(b+1,b+cnt+1,q[i][2])-b;
	int uu=30;
	for (int i=1;i<=m;i++) ans[i]=1;
	while (uu--)
	{
		for (int i=1;i<=n;i++) tree[i]=0,d[i]=0;
		for (int i=1;i<=cnt;i++) c[i]=rnd()%2;
		for (int i=1;i<=n;i++) update(i,c[a[i]]);
		for (int i=1;i<=m;i++)
		{
			if (q[i][0]==1) update(q[i][1],c[q[i][2]]);
			else 
			{
				int res=ask(q[i][2])-ask(q[i][1]-1);
				//cout << res << " " << q[i][3] << endl;
				if (res%q[i][3]!=0) ans[i]=0;
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		if (q[i][0]==2)
		{
			if (ans[i]) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}