// By: Little09
// Problem: D. Madoka and the Best School in Russia
// Contest: Codeforces - Codeforces Round #777 (Div. 2)
// URL: https://codeforces.ml/contest/1647/problem/D
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
ll n,m; 
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

bool isprime(int x)
{
	for (int i=2;i<=sqrt(x);i++)
	{
		if (x%i==0) return 0;
	}
	return 1;
}

void work()
{
	n=read(),m=read();
	int cnt=0;
	while (n%m==0)
	{
		cnt++;
		n/=m;
	}
	if (cnt<=1)
	{
		printNO;
		return;
	}
	if (n==1)
	{
		if (cnt==2)
		{
			printNO;
			return;
		}
		if (isprime(m)==0)
		{
			printYES;
			return;
		}
		printNO;
		return;
	}
	if (isprime(n)==0)
	{
		printYES;
		return;
	}
	if (cnt>2&&isprime(m)==0&&(cnt!=3||m!=n*n))
	{
		printYES;
		return;
	}
	printNO;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}