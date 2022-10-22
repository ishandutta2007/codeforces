// LUOGU_RID: 90482602
// Author: Little09
// Problem: F. Ela and Prime GCD
// Contest: Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/F
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
int a[N],id[N],pr[N];
pii b[N];
 
void dfs(int x,vector<int> ans)
{
	if (x==m+1)
	{
		for (int i:ans)
		{
			int cnt=0;
			for (int j=1;j<=m;j++) 
			{
				pr[++cnt]=i%(b[j].fi+1);
				i/=(b[j].fi+1);
			}
			for (int j=1;j<=m;j++) cout << pr[id[j]] << " ";
			cout << endl;
		}
		return;
	}
	int len=ans.size();
	if (len==1) return dfs(x+1,{1,3,2}); 
	vector<int> res(len*2+1);
	for (int i=0;i<=len-2;i++)
	{
		res[i]=ans[i],res[2*len-2-i]=ans[i];
		if (i&1) res[i]+=len+1;
		else res[2*len-2-i]+=len+1;
	}
	res[len-1]=ans[len-1],res[2*len-1]=len+1,res[2*len]=len+1+ans[len-1];
	dfs(x+1,res);
}
 
 
void work()
{
	cin >> m;
	for (int i=1;i<=m;i++) cin >> a[i];
	for (int i=1;i<=m;i++) b[i].fi=a[i],b[i].se=i;
	sort(b+1,b+m+1,greater<pii>());
	for (int i=1;i<=m;i++) id[b[i].se]=i;
	if (b[1].fi>=4)
	{
		cout << -1 << endl;
		return;
	}
	else if (b[1].fi==3)
	{
		if (m>=2&&b[2].fi>=2) cout << -1 << endl;
		else dfs(2,{2,1,3});
		return;
	}
	else if (b[1].fi==2)
	{
		if (m>=3&&b[3].fi>=2) cout << -1 << endl;
		else if (m==1||b[2].fi==1) dfs(2,{2,1});
		else dfs(3,{8,1,7,3,5,6,4,2});
		return;
	}
	else
	{
		dfs(2,{1});
		return;
	}
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