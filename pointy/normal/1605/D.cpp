// By: Little09
// Problem: D. Treelabeling
// Contest: Codeforces - Codeforces Round #754 (Div. 2)
// URL: https://codeforces.ml/contest/1605/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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

const int N=200005;
int n,m,T; 
int a[N],b[N],cnta,cntb;

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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
vector<int>t[N];
void add(int x,int y)
{
	t[x].push_back(y);
}
int col[N],flag[N];
void dfs(int x,int fa,int c)
{
	col[x]=c;
	for (int i=0;i<t[x].size();i++)
	{
		if (t[x][i]==fa) continue;
		dfs(t[x][i],x,(c^1));
	}
}
int fff(int x)
{
	for (int i=20;i>=0;i--)
	{
		if (x&(1<<i)) return (1<<i);
	}
	return 0;
}
void work()
{
	n=read();
	for (int i=1;i<=n;i++) col[i]=-1,flag[i]=-1;
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs(1,0,0);
	int tot0=0,tot1=0,tot=0;
	for (int i=1;i<=n;i++)
	{
		if (col[i]==0) tot0++;
		else tot1++;
	}
	int ans=0;
	if (tot0<tot1) tot=tot0;
	else ans=1,tot=tot1;
	for (int i=1;i<=n;i++)
	{
		int x=fff(i);
		if ((x&tot)==x) flag[i]=0;
		else flag[i]=1;
	}
	cnta=0,cntb=0;
	for (int i=1;i<=n;i++)
	{
		if (flag[i]==0) a[++cnta]=i;
		else b[++cntb]=i;
	}
	for (int i=1;i<=n;i++)
	{
		if (col[i]==ans)
		{
			printf("%d ",a[cnta--]);
		}
		else printf("%d ",b[cntb--]);
	}
	puts("");
	return;
}

int main()
{
	int tp=0;
	//0 : many test cases
	//1 : one test case
	if (tp==0) T=read();
	else T=1;
	while (T--)
	{
		work();
	}
	return 0;
}