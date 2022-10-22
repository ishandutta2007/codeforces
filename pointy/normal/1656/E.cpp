// Author: Little09
// Problem: E. Equal Tree Sums
// Contest: CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/E
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

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];
vector<int>t[N];
void add(int x,int y)
{
	t[x].push_back(y);
}
void dfs(int x,int fa,int dis)
{
	int res=0;
	if (dis==1) res=-1;
	else if (fa!=0) res=1;
	for (int i:t[x])
	{
		if (i==fa) continue;
		if (dis==0) res++;
		else res--;
		dfs(i,x,1-dis);
	}
	a[x]=res;
}

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y),add(y,x);
	}
	dfs(1,0,0);
	for (int i=1;i<=n;i++) cout << a[i] << " ";
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