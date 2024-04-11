// Author: Little09
// Problem: CF1348F Phoenix and Memory
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1348F
// Memory Limit: 250 MB
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
int n,m; 
int ans[N],b[N];
struct point
{
	int x,y,id;
	bool operator < (const point &o) const
	{
		return y<o.y;
	}
}a[N],c[N];
bool cmp(point x,point y)
{
	return x.x<y.x;
}
multiset<point>s;
vector<int>t[N];
multiset<int>q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i].x >> a[i].y;
	for (int i=1;i<=n;i++) a[i].id=i,c[i]=a[i];
	sort(a+1,a+n+1,cmp);
	int tot=1;
	for (int i=1;i<=n;i++)
	{
		while (tot<=n&&a[tot].x==i) s.insert(a[tot++]);
		point u=*s.begin();
		s.erase(s.begin());
		ans[u.id]=i;
	}
	for (int i=1;i<=n;i++) b[ans[i]]=i;
	for (int i=1;i<=n;i++) t[c[i].x].push_back(i);
	for (int i=1;i<=n;i++)
	{
		for (int j:t[i]) q.insert(ans[j]);
		auto d=q.upper_bound(i);
		if (d!=q.end()&&*d<=c[b[i]].y)
		{
			cout << "NO" << endl;
			for (int j=1;j<=n;j++) cout << ans[j] << " ";
			cout << endl;
			swap(ans[b[i]],ans[b[*d]]);
			for (int j=1;j<=n;j++) cout << ans[j] << " ";
			cout << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for (int i=1;i<=n;i++) cout << ans[i] << " ";
	return 0;
}