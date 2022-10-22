// Author: Little09
// Problem: D. Permutation Addicts
// Contest: Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/D
// Memory Limit: 512 MB
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N];
vector<int>t[N];
bool cmp(int x,int y)
{
	return b[x]<b[y];
}
int cnt,ans[N],maxx;

void dfs(int x,int tp)
{
	if (t[x].size()==0) return;
	int las=-1;
	for (int i:t[x])
	{
		ans[++cnt]=i;
		las=i;
		if (tp==0) maxx=max(maxx,i);
	}
	if (las!=-1&&b[las]!=0)
	{
		dfs(las,tp^1);
	}
}

void work()
{
	cin >> n;
	for (int i=0;i<=n+1;i++) t[i].clear(),b[i]=0;
	for (int i=1;i<=n;i++) cin >> a[i];
	int tp=0;
	cnt=0,maxx=0;
	for (int i=1;i<=n;i++)
	{
		b[a[i]]++;
		t[a[i]].push_back(i);
		if (a[i]==n+1) tp=n+1;
	}
	for (int i=0;i<=n+1;i++)
	{
		sort(t[i].begin(),t[i].end(),cmp);
	}
	if (tp==0) dfs(tp,1);
	else dfs(tp,0);
	cout << maxx << endl;
	for (int i=1;i<=cnt;i++) cout << ans[i] << " ";
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