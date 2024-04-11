// Author: Little09
// Problem: C2. Balanced Removals (Harder)
// Contest: Codeforces Global Round 5
// URL: https://codeforces.com/contest/1237/problem/C2
// Memory Limit: 512 MB
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
map<ll,ll>t,q;
ll a[N],b[N],c[N],tot,d[N];
bool used[N];
vector<int>w[N];
bool cmpc(int x,int y)
{
	return c[x]<c[y];
}
bool cmpb(int x,int y)
{
	return b[x]<b[y];
}

bool cmpa(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
	for (int i=1;i<=n;i++)
	{
		ll tmp=a[i]*1000000000+b[i];
		if (t[tmp]==0) t[tmp]=++tot;
		w[t[tmp]].push_back(i);
	}
	for (int i=1;i<=tot;i++) sort(w[i].begin(),w[i].end(),cmpc);
	for (int i=1;i<=tot;i++)
	{
		if (w[i].size()>1)
		{
			int las=-1;
			for (int j:w[i])
			{
				if (las==-1) las=j;
				else 
				{
					used[las]=1,used[j]=1;
					cout << las << " " << j << endl;
					las=-1;
				}
			}
		}
	}
	for (int i=1;i<=tot;i++) w[i].clear();
	t.clear();
	tot=0;
	for (int i=1;i<=n;i++)
	{
		if (used[i]) continue;
		ll tmp=a[i];
		if (t[tmp]==0) t[tmp]=++tot;
		w[t[tmp]].push_back(i);
	}
	for (int i=1;i<=tot;i++) sort(w[i].begin(),w[i].end(),cmpb);
	for (int i=1;i<=tot;i++)
	{
		if (w[i].size()>1)
		{
			int las=-1;
			for (int j:w[i])
			{
				if (las==-1) las=j;
				else 
				{
					used[las]=1,used[j]=1;
					cout << las << " " << j << endl;
					las=-1;
				}
			}
		}
	}
	int cnt=0;
	for (int i=1;i<=n;i++) if (used[i]==0) d[++cnt]=i;
	sort(d+1,d+cnt+1,cmpa);
	for (int i=1;i<=cnt;i+=2) cout << d[i] << " " << d[i+1] << endl;
	return 0;
}