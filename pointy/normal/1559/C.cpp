// By: Little09
// Problem: C. Mocha and Hiking
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/C
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
int n,m,T; 
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

void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (a[1]==1)
	{
		printf("%d ",n+1);
		for (int i=1;i<=n;i++) printf("%d ",i);
		puts("");
		return;
	}
	int sum=0;
	for (int i=1;i<=n;i++) sum+=a[i];
	if (sum==0) 
	{
		for (int i=1;i<=n;i++) printf("%d ",i);
		printf("%d ",n+1);
		puts("");
		return;
	}
	int u=-1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==1) 
		{
			u=i;
			break;
		}
	}
	for (int i=1;i<u;i++) printf("%d ",i);
	printf("%d ",n+1);
	for (int i=u;i<=n;i++) printf("%d ",i);
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