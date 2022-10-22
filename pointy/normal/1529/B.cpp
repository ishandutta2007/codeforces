// Author: Little09
// Problem: B. Sifid and Strange Subsequences
// Contest: Codeforces Round #722 (Div. 2)
// URL: https://codeforces.com/contest/1529/problem/B
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

void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int ans=0,tot=2e9;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<=0) 
		{
			ans++;
			if (i!=1) tot=min(tot,a[i]-a[i-1]);
		}
		else
		{
			if (a[i]<=tot) ans++;
			break;
		}
	}
	cout << ans << endl;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}