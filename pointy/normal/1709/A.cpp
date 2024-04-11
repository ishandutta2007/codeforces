// Author: Little09
// Problem: A. Three Doors
// Contest: Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/A
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];

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

int ans;
bool used[4];
void dfs(int x)
{
	if (x<1||used[x]) return;
	used[x]=1;
	ans++;
	dfs(a[x]);
}

void work()
{
	n=read(),ans=0;
	used[1]=used[2]=used[3]=0;
	for (int i=1;i<=3;i++) a[i]=read();
	dfs(n);
	if (ans==3) printYES;
	else printNO;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}