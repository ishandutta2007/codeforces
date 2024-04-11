// Author: Little09
// Problem: C. Recover an RBS
// Contest: Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/C
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
char a[N],b[N];

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
	cin >> (a+1);
	n=strlen(a+1);
	int tot=0,pp=0;
	for (int i=1;i<=n;i++) tot+=(a[i]=='('),pp+=(a[i]==')');
	if (tot==n/2||pp==n/2)
	{
		printYES;
		return;
	}
	int s=0;
	int x=0,y=n;
	for (int i=1;i<=n;i++)
	{
		if (a[i]=='(') s++;
		else if (a[i]==')') s--;
		else 
		{
			if (tot<n/2) s++,tot++,a[i]='(',x=max(x,i);
			else s--,pp++,a[i]=')',y=min(y,i);
		}
	}
	swap(a[x],a[y]);
	for (int i=1;i<=n;i++)
	{
		if (a[i]=='(') s++;
		else if (a[i]==')') s--;
		if (s<0)
		{
			printYES;
			return;
		}
	}
	printNO;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}