// Author: Little09
// Problem: CF1305E Kuroni and the Score Distribution
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1305E
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

int main()
{
	n=read(),m=read();
	int res=0;
	for (int i=1;i<=n;i++)
	{
		res+=max(0,n-i-i);
	}
	if (m>res)
	{
		cout << -1;
		return 0;
	}
	for (int i=1;i<=n;i++) a[i]=i;
	int l=n;
	while (res>m)
	{
		if (a[l]>a[l-1]+a[l-2]) l--;
		a[l]+=2,res--;
	}
	for (int i=1;i<=l;i++) cout << a[i] << " ";
	int tmp=1e8;
	for (int i=l+1;i<=n;i++)
	{
		cout<<tmp<<" ";
		tmp+=n+5;
	}
	return 0;
}