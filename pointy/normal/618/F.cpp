// By: Little09
// Problem: CF618F Double Knapsack
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF618F
// Memory Limit: 250 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define mem(x) memset(x,-1,sizeof(x))
#define ll long long
ll a[N],b[N],c[N],d[N];
ll ans[N][2];
bool flag;
int n;
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
void print(int x,int y,int l,int r)
{
	if (flag) swap(x,l),swap(y,r);
	printf("%d\n",y-x+1);
	for (int i=x;i<=y;i++) printf("%d ",i);
	printf("\n%d\n",r-l+1);
	for (int i=l;i<=r;i++) printf("%d ",i);
}
int main()
{
	n=read();
	mem(ans);
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=1;i<=n;i++) c[i]=a[i]+c[i-1];
	for (int i=1;i<=n;i++) d[i]=b[i]+d[i-1];
	if (c[n]>d[n]) 
	{
		flag=1;
		for (int i=1;i<=n;i++) swap(c[i],d[i]);
	}
	for (int i=0;i<=n;i++)
	{
		int u=lower_bound(d,d+n+1,c[i])-d;
		int v=d[u]-c[i];
		if (ans[v][0]!=-1)
		{
			print(ans[v][0]+1,i,ans[v][1]+1,u);
			return 0;
		}
		ans[v][0]=i,ans[v][1]=u;
	}
	return 0;
}