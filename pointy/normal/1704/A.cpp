// Author: Little09
// Problem: A. Two 0-1 Sequences
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/A
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N];

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

void work()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=readchar()-'0';
	for (int i=1;i<=m;i++) b[i]=readchar()-'0';
	int t=n;
	for (int i=m;i>1;i--)
	{
		if (a[t]!=b[i])
		{
			printNO;
			return;
		}
		t--;
	}
	bool fl=0;
	for (int i=t;i>=1;i--)
	{
		if (a[i]==b[1]) fl=1;
	}
	if (fl) printYES;
	else printNO;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}