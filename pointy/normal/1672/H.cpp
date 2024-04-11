// By: Little09
// Problem: CF1672H Zigu Zagu
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1672H
// Memory Limit: 2700 MB
// Time Limit: 250000 ms
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
int n,m; 
int a[N],s[N][2];

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

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=readchar()-'0';
	for (int i=2;i<=n;i++) 
	{
		if (a[i]==a[i-1]) s[i][a[i]]=1;
	}
	for (int i=2;i<=n;i++) s[i][0]+=s[i-1][0];
	for (int i=2;i<=n;i++) s[i][1]+=s[i-1][1];
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read();
		int x=s[r][0]-s[l][0],y=s[r][1]-s[l][1];
		printf("%d\n",max(x,y)+1);
	}
	return 0;
}