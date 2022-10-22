// By: Little09
// Problem: CF1698E PermutationForces II
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1698E
// Memory Limit: 250 MB
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
const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,s; 
int a[N],b[N],p[N],c[N];
bool used[N];
ll sum[N];

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
	n=read(),s=read();
	for (int i=1;i<=n;i++) p[i]=-1,used[i]=0;
	for (int i=1;i<=n;i++) a[i]=read(),c[a[i]]=i;
	ll ans=1;
	for (int i=1;i<=n;i++) sum[i]=1;
	for (int i=1;i<=n;i++) 
	{
		b[i]=read();
		if (b[i]!=-1) p[b[i]]=i;
	}
	int tot=0;
	for (int i=1;i<=n;i++)
	{
		while (tot<i+s&&tot<n) ++tot,used[c[tot]]=1;
		if (p[i]!=-1)
		{
			if (used[p[i]]==0)
			{
				printf("0\n");
				return;
			}
			sum[a[p[i]]]=0;
		}
	}
	ll tu=0;
	for (int i=1;i<=n;i++) sum[i]+=sum[i-1];
	for (int i=1;i<=n;i++)
	{
		if (p[i]==-1)
		{
			int u=min(n,i+s);
			ans=(ans*(sum[u]-tu))%mod;
			tu++;
		}
	}
	printf("%lld\n",ans);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}