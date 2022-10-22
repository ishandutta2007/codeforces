// Author: Little09
// Problem: E. Cross Swapping
// Contest: Codeforces Round #812 (Div. 2)
// URL: https://codeforces.com/contest/1713/problem/E
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

const int N=2005;
int n,m; 
int a[N][N];
int fa[N];
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int h[N],nxt[N],v[N],t[N],cnt;
int w[N];
void add(int x,int y,int z)
{
	//cout << x << " " << y << " " << z << endl;
	t[++cnt]=y;
	v[cnt]=z;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
void dfs(int x,int f)
{
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]==f) continue;
		w[t[i]]=(w[x]^v[i]);
		dfs(t[i],x);
	}
}
void merge(int x,int y,int z)
{
	int x1=find(x),y1=find(y);
	if (x1==y1) return;
	add(x,y,z),add(y,x,z);
	fa[x1]=y1;
}

void work()
{
	cin >> n;
	cnt=0;
	for (int i=0;i<=2*n;i++) w[i]=0,h[i]=0,nxt[i]=0,v[i]=0,t[i]=0,fa[i]=i;
	for (int i=1;i<=n;i++) 
	{
		for (int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (a[i][j]==a[j][i]) continue;
			merge(i,j,a[i][j]>a[j][i]);
		}
	}
	//return ;
	for (int i=1;i<=n;i++)
	{
		if (find(i)==i)
		{
			w[i]=0;
			dfs(i,0);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (w[i]^w[j]) cout << a[j][i] << " ";
			else cout << a[i][j] << " ";
		}
		cout << endl;
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