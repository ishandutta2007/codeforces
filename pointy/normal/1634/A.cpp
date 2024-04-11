// By: Little09
// Problem: A. Reverse and Concatenate
// Contest: Codeforces - Codeforces Round #770 (Div. 2)
// URL: https://codeforces.com/contest/1634/problem/A
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
int n,m; 
char a[N];

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
	for (int i=1;i<=n;i++) a[i]=readchar();
	if (m==0)
	{
		printf("1\n");
		return;
	}
	bool flag=0;
	for (int i=1;i<=n;i++) if (a[i]!=a[n+1-i]) flag=1;
	if (flag==0)
	{
		printf("1\n");
		return;
	}
	printf("2\n");
	return;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}