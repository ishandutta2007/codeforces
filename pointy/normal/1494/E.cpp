// Author: Little09
// Problem: CF1494E A-Z Graph
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1494E
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

const int N=200005;
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

map<int,int>q[N];
int main()
{
	n=read(),m=read();
	int ans=0,res=0;
	while (m--)
	{
		char x=readchar();
		if (x=='+')
		{
			int x=read(),y=read(),z=readchar()-'a'+1;
			if (q[y][x]!=0) ans++;
			if (q[y][x]==z) res++;
			q[x][y]=z;
		}
		else if (x=='-')
		{
			int x=read(),y=read();
			if (q[y][x]!=0) 
			{
				ans--;
				if (q[x][y]==q[y][x]) res--;
			}
			q[x][y]=0;
		}
		else 
		{
			int k=read();
			if (k%2==0)
			{
				if (res>0) printYES;
				else printNO;
			}
			else
			{
				if (ans>0) printYES;
				else printNO;
			}
		}
	}
	return 0;
}