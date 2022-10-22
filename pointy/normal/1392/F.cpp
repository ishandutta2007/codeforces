// By: Little09
// Problem: CF1392F Omkar and Landslide
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1392F
// Memory Limit: 250 MB
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

const int N=1e6+5;
int n,m,T; 
ll a[N];

inline ll read()
{
    ll F=1,ANS=0;
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
	ll sum=0;
	for (int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	for (int i=1;i<=n;i++) a[i]=i,sum-=a[i];
	ll x=sum/n;
	for (int i=1;i<=n;i++) a[i]+=x;
	sum-=x*n;
	for (int i=1;i<=n;i++) 
	{
		if (sum>0) a[i]++,sum--;
	}
	for (int i=1;i<=n;i++) printf("%lld ",a[i]);
	return;
}

int main()
{
	int tp=1;
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