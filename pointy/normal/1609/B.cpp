// By: Little09
// Problem: B. William the Vigilant
// Contest: Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/B
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];

bool check(int x)
{
	if (x<1) return 0;
	if (a[x]!=0) return 0;
	if (a[x+1]!=1) return 0;
	if (a[x+2]!=2) return 0;
	if (x<=n-2) return 1;
	return 0;
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
	int ans=0;
	for (int i=1;i<=n;i++) a[i]=readchar()-'a';
	for (int i=1;i<=n;i++) ans+=check(i);
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=readchar()-'a';
		for (int i=x;i>=x-2;i--) ans-=check(i);
		a[x]=y;
		for (int i=x;i>=x-2;i--) ans+=check(i);
		printf("%d\n",ans);
	}
}

int main()
{
	int T=1;
	while (T--) work();
	return 0;
}