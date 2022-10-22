// Author: Little09
// Problem: B. Shurikens
// Contest: Codeforces Round #679 (Div. 1, based on Technocup 2021 Elimination Round 1)
// URL: https://codeforces.com/contest/1434/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[N],top,b[N],c[N];
priority_queue<int>q;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int tot=0;
	for (int i=1;i<=2*n;i++)
	{
		char x;
		cin >> x;
		if (x=='+')
		{
			++tot;
			a[++top]=tot;
			c[i]=-1;
		}
		else 
		{
			if (top==0)
			{
				printNO;
				return 0;
			}
			int y;
			cin >> y;
			b[a[top]]=y;
			top--;
			c[i]=y;
		}
	}
	int uu=0;
	for (int i=1;i<=2*n;i++)
	{
		if (c[i]==-1)
		{
			++uu;
			q.push(-b[uu]);
		}
		else
		{
			int u=q.top();
			q.pop();
			if (-u!=c[i])
			{
				printNO;
				return 0;
			}
		}
	}
	printYES;
	for (int i=1;i<=n;i++) cout << b[i] << " ";
	return 0;
}