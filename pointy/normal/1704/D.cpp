// Author: Little09
// Problem: D. Magical Array
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/D
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

struct point
{
	ll x,y;
}a[N];
bool cmp(point x,point y)
{
	return x.x<y.x;
}

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
	n=read(),m=read();
	
	for (int i=1;i<=n;i++)
	{
		ll s=0,sum=0;
		for (int j=1;j<=m;j++)
		{
			ll x=read();
			s=(s+x);
			sum=(sum+s);
		}
		a[i].x=sum,a[i].y=i;
	}
	sort(a+1,a+n+1,cmp);
	printf("%lld %lld\n",a[1].y,a[2].x-a[1].x);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}