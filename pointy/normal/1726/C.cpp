// Author: Little09
// Problem: C. Jatayu's Balanced Bracket Sequence
// Contest: Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.com/contest/1726/problem/C
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
char a[N];
int fa[N],ans;
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y) return;
	ans++;
	fa[x]=y;
}
int st[N],top;


void work()
{
	cin >> n;
	ans=0;
	for (int i=1;i<=2*n;i++) cin >> a[i];
	top=0;
	for (int i=1;i<=2*n;i++) fa[i]=i;
	for (int i=1;i<=2*n;i++)
	{
		if (a[i]=='(') st[++top]=i;
		else 
		{
			merge(i,st[top]);
			top--;
		}
	}
	for (int i=1;i<2*n;i++) 
	{
		if (a[i]==')'&&a[i+1]=='(') merge(i,i+1);
	}
	cout << 2*n-ans << endl;
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