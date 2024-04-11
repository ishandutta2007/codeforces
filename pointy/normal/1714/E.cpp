// Author: Little09
// Problem: E. Add Modulo 10
// Contest: Codeforces Round #811 (Div. 3)
// URL: https://codeforces.com/contest/1714/problem/E
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
int f(int x)
{
	if (x%10==0) return x;
	if (x%5==0) return f(x+5);
	x%=20;
	if (x==16||x==18) return x;
	return f(x+x%10);
}
void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=f(read());
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=a[1])
		{
			printNo;
			return;
		}
	}
	printYes;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}