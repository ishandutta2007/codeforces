// Author: Little09
// Problem: CF1699E Three Days Grace
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1699E
// Memory Limit: 250 MB
// Time Limit: 4000 ms
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

const int N=5e6+5;
int n,m; 
int a[N],b[N],tot,f[N],ans;
void update(int u,int x)
{
	if (a[u]==0)
	{
		f[u]=x;
	}
	else
	{
		b[f[u]]--;
		f[u]=x;
		b[f[u]]++;
		while (b[tot]==0) tot--;
	}
}
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
	for (int i=1;i<=m+1;i++) a[i]=0;
	for (int i=1;i<=n;i++) a[read()]=1;
	for (int i=1;i<=m+1;i++) b[i]=0,f[i]=m+1;
	for (int i=1;i<=m;i++)
	{
		if (a[i]==1) b[m+1]++;
	}
	tot=m+1,ans=m+1;
	for (int i=m;i>=1;i--)
	{
		update(i,i);
		for (int j=2;i*j<=m;j++)
		{
			if (f[i*j]>f[j]) update(i*j,f[j]);
		}
		if (tot<=m) ans=min(ans,tot-i);
	}
	printf("%d\n",ans);
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}