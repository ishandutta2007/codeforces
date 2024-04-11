// By: Little09
// Problem: C. Bakry and Partitioning
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.ml/contest/1592/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;

vector<int>t[N];
int n;
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
queue<int>q;
bool used[N];
int a[N],fa[N],cnt,ans;
void askall()
{
	printf("? %d ",n);
	for (int i=1;i<=n;i++) printf("%d ",i);
	cout << endl;
	fflush(stdout);
	ans=read();
}
bool check(int x)
{
	printf("? %d ",x);
	for (int i=1;i<=x;i++) printf("%d ",a[i]);
	cout << endl;
	fflush(stdout);
	int u=read();
	if (u==ans) return 1;
	return 0;
}
void find(int x)
{
	printf("! %d %d\n",a[x],fa[a[x]]);
	fflush(stdout);
	
}
int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		t[x].push_back(y),t[y].push_back(x);
	}
	q.push(1);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		used[u]=1;
		a[++cnt]=u;
		for (int i=0;i<t[u].size();i++)
		{
			if (used[t[u][i]]) continue;
			q.push(t[u][i]);
			fa[t[u][i]]=u;
		}
	}
	askall();
	int l=2,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	find(l);
	return 0;
}