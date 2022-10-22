// Author: Little09
// Problem: D. Playlist
// Contest: Codeforces Round #709 (Div. 2, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1484/problem/D
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
int n,m; 
int a[N],fa[N];
bool b[N];
int ans[N],top,pre[N];
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int findlast(int x)
{
	int u=find(x);
	if (u==n+1) return find(1);
	else return u;
}
set<int>s;
void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n+1;i++) fa[i]=i;
	for (int i=2;i<=n;i++) 
	{
		if (__gcd(a[i-1],a[i])==1) b[i]=1;
		else b[i]=0;
	}
	if (__gcd(a[1],a[n])==1) b[1]=1;
	else b[1]=0;
	for (int i=2;i<=n;i++) pre[i]=i-1;
	pre[1]=n;
	s.clear();
	for (int i=1;i<=n;i++) if (b[i]) s.insert(i);
	top=0;
	int x=1;
	for (int i=1;i<=n;i++)
	{
		if (s.empty()) break;
		auto u=s.upper_bound(x);
		// cout << "s ";
		// for (int j:s) cout << j << " ";
		// cout << endl;
		if (u==s.end()) 
		{
			//cout << "666" << endl;
			x=0;
			u=s.upper_bound(x);
		}
		//cout << (*u) << endl;
		//if (u==s.end()) break;
		// if ((*u)==415)
		// {
			// cout << s.size() << endl;
			// s.erase(415);
			// cout << s.size() << endl;
			// exit(0);
		// }
		int v=(*u);
		//cout << v << endl;
		s.erase(v);
		//if ((*u)==415) exit(0);
		//cout << (*u) << endl;
		ans[++top]=v;
		//cout << "nxtuuu " << endl;
		//cout << "111 " << endl;
		fa[v]=v+1;
		int nxt=findlast(v);
		if (nxt==n+1) break;
		pre[nxt]=pre[v];
		assert(nxt<=n);
		//cout << "nxt " << nxt << endl;
		if (b[nxt]) s.erase(nxt);
		b[nxt]=(__gcd(a[nxt],a[pre[nxt]])==1);
		if (b[nxt]) s.insert(nxt);
		x=findlast(v);
	}
	cout << top << " ";
	for (int i=1;i<=top;i++) cout << ans[i] << " ";
	cout << endl;
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