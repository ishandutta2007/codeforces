// Author: Little09
// Problem: B. Also Try Minecraft
// Contest: Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/B
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
ll a[N],b[N],c[N];

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
	//n=read();
	//for (int i=1;i<=n;i++) a[i]=read();
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=a[i+1]-a[i];
	for (int i=1;i<=n;i++) c[i]=a[i]-a[i+1];
	for (int i=1;i<=n;i++) b[i]=max(0ll,b[i]);
	for (int i=1;i<=n;i++) c[i]=max(0ll,c[i]);
	for (int i=1;i<=n;i++) b[i]+=b[i-1],c[i]+=c[i-1];
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read();
		if (l<r) printf("%lld\n",c[r-1]-c[l-1]);
		else printf("%lld\n",b[l-1]-b[r-1]);
	}
	return 0;
}