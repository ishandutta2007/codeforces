// Author: Little09
// Problem: F. Colouring Game
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/F
// Memory Limit: 256 MB
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
char a[N];

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

int sg[1001];
bool u[1001];
void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=(readchar()=='B');
	int u=0,v=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0) u++;
		else v++;
	}
	if (u<v) printf("Bob\n");
	else if (u>v) printf("Alice\n");
	else
	{
		int las=1,ans=0;
		for (int i=1;i<=n;i++)
		{
			if (i==1||a[i]==a[i-1])
			{
				ans^=sg[las];
				las=1;
			}
			else las++;
			if (las>=1000) las-=34;
		}
		ans^=sg[las];
		if (ans) printf("Alice\n");
		else printf("Bob\n");
	}
}
int main()
{
	sg[1]=0;
	for (int i=2;i<=1000;i++)
	{
		mem(u);
		for (int j=0;j<=i-2;j++)
		{
			u[sg[j]^sg[i-2-j]]=1;
		}
		for (int j=0;;j++)
		{
			if (u[j]==0)
			{
				sg[i]=j;
				break;
			}
		}
	}
	// for (int i=1;i<=1000;i++) cout << sg[i] << " \n";
	// cout << endl;
	int T=read();
	while (T--) work();
	return 0;
}