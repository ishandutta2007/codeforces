// By: Little09
// Problem: D. Cyclic Rotation
// Contest: Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/D
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N],c[N];

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
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=0;i<=n;i++) c[i]=0;
	int i=1;
	for (int tot=1;tot<=n;tot++)
	{
		while (1)
		{
			//cout << i << " " << tot << " " << c[1] << endl;
			if (a[i]==b[tot])
			{
				i++;
				break;
			}
			if (tot!=1&&b[tot]==b[tot-1]&&c[b[tot]]>0)
			{
				c[b[tot]]--;
				//cout << i << " " << tot << " " << c[1] << endl;
				break;
			}
			c[a[i]]++;	
			i++;
			if (i>n)
			{
				printNO;
				return;
			}
		}
		
	}
	for (int i=1;i<=n;i++)
	{
		if (c[i]!=0)
		{
			printNO;
			return;
		}
	}
	printYES;
}

int main()
{
	int T=read();
	while (T--) work();
	return 0;
}