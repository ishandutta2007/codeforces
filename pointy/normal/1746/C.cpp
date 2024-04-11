// Author: Little09
// Problem: C. Permutation Operations
// Contest: Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int a[N],ans[N];
struct point
{
	int x,id;
}b[N];
bool cmp(point x,point y)
{
	return x.x<y.x;
}

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	a[0]=0;
	for (int i=1;i<=n;i++) b[i].x=max(a[i-1]-a[i],0),b[i].id=i;
	// for (int i=1;i<=n;i++) cout << b[i].x << " ";
	// cout << endl;
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++) ans[i]=b[i].id;
	for (int i=1;i<=n;i++) cout << ans[i] << " ";
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