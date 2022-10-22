// Author: Little09
// Problem: CF1144G Two Merged Sequences
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1144G
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,d[N]; 
bool ans[N];
int a,b,c;

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
int main()
{
	n=read();
	b=-1,c=1e9;
	for (int i=1;i<=n;i++) d[i]=read();
	for (int i=1;i<=n;i++)
	{
		a=d[i];
		if (a<=b&&a>=c)
		{
			printNO;
			return 0;
		}
		if (a<=b) c=a,ans[i]=1;
		else if (a>=c) b=a,ans[i]=0;
		else if (d[i+1]>a) b=a,ans[i]=0;
		else c=a,ans[i]=1;
	}
	printYES;
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}