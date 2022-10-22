// By: Pointy
// Problem: C. Menorah
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/C
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=100005;
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
	n=read();
	int suma=0,sumb=0;
	for (int i=1;i<=n;i++) a[i]=readchar()-'0',suma+=a[i];
	for (int i=1;i<=n;i++) b[i]=readchar()-'0',sumb+=b[i];
	if (suma+sumb!=n+1&&suma!=sumb)
	{
		printf("-1\n");
		return;
	}
	int res=1e9;
	if (suma==sumb)
	{
		int ans=0;
		for (int i=1;i<=n;i++) ans+=(a[i]!=b[i]);
		res=min(res,ans);
	}
	if (suma+sumb==n+1)
	{
		int ans=0;
		for (int i=1;i<=n;i++) ans+=(a[i]==b[i]);
		res=min(res,ans);
	}
	cout << res << endl;
	return;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}