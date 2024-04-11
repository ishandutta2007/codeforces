// By: Little09qwq
// Problem: C. Fishingprince Plays With Array
// Contest: Codeforces Global Round 21
// URL: https://codeforces.com/contest/1696/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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
int n,m,k; 
int a[N][2],b[N][2];

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
	int cntn=0,cntk=0;
	for (int i=1;i<=n;i++) 
	{
		int x=read(),y=x;
		while (x%m==0) x/=m;
		if (cntn!=0&&a[cntn][0]==x) a[cntn][1]+=y/x;
		else a[++cntn][0]=x,a[cntn][1]=y/x;
	}
	k=raed();
	for (int i=1;i<=k;i++) 
	{
		int x=read(),y=x;
		while (x%m==0) x/=m;
		if (cntk!=0&&b[cntk][0]==x) b[cntk][1]+=y/x;
		else b[++cntk][0]=x,b[cntk][1]=y/x;
	}
	if (cntn!=cntk) printNo;
	else
	{
		for (int i=1;i<=cntn;i++)
		{
			if (a[i][0]!=b[i][0]||a[i][1]!=b[i][1])
			{
				printNo;
				return;
			}
		}
		printYes;
	}
}

signed main()
{
	int T=read();
	while (T--) work();
	return 0;
}