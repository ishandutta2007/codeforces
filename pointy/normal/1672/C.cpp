// By: Little09
// Problem: C. Unequal Array
// Contest: Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/C
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


bool check(int x)
{
	if (x!=1&&a[x-1]==a[x]) return 1;
	if (x!=n&&a[x+1]==a[x]) return 1;
	return 0;
}

void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int l=n+1,r=-1;
	if (n==1)
	{
		printf("0\n");
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (check(i)) l=min(l,i),r=max(i,r);
	}
	int len=r-l+1;
	if (len<=2) printf("0\n");
	else if (len==3) printf("1\n");
	else printf("%d\n",len-3);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}