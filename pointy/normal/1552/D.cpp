// By: Little09
// Problem: D. Array Differentiation
// Contest: Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/D
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=5000005;
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
int calc(int x)
{
	int res=0;
	for (int i=0;i<n;i++)
	{
		if (x&(1<<i)) res+=a[i];
	}
	return res;
}
void work()
{
	n=read();
	mem(b);
	for (int i=0;i<n;i++) a[i]=abs(read());
	for (int i=0;i<(1<<n);i++)
	{
		int c=calc(i);
		if (b[c]!=0) 
		{
			printYES;
			return;
		}
		b[c]=1;
	}
	printNO;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}