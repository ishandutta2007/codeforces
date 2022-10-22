// By: Little09qwq
// Problem: CF1687A The Enchanted Forest
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1687A
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
ll n,m; 
ll a[N];

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
	for (int i=1;i<=n;i++) a[i]=read();
	if (m<=n)
	{
		for (int i=2;i<=n;i++) a[i]+=a[i-1];
		ll ans=0;
		for (int i=m;i<=n;i++)
		{
			ans=max(ans,a[i]-a[i-m]);
		}
		ans=ans+m*(m-1)/2;
		printf("%lld\n",ans);
	}
	else
	{
		ll ans=0;
		for (int i=1;i<=n;i++) ans+=a[i];
		m--;
		for (int i=1;i<=n;i++) ans+=m,m--;
		printf("%lld\n",ans);
	}
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}