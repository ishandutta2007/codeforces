// By: Little09
// Problem: C. Complex Market Analysis
// Contest: Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/C
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
int a[N],c[N];
vector<int>b[N];

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
	for (int i=1;i<=n;i++) 
	{
		a[i]=read();
		int x=a[i];
		for (int j=2;j<=sqrt(x);j++)
		{
			if (x%j==0) 
			{
				a[i]=-1;
				break;
			}
		}
	}
	for (int i=0;i<=m;i++) b[i].clear();
	for (int i=1;i<=n;i++)
	{
		b[i%m].push_back(a[i]);
	}
	ll ans=0;
	for (int i=0;i<m;i++)
	{
		int tmp=0,pre=-1;
		for (int j=0;j<b[i].size();j++)
		{
			if (b[i][j]==-1) 
			{
				tmp=0,pre=-1;
			}
			else if (b[i][j]==1) 
			{
				tmp++;
				ans+=pre+1;
			}
			else 
			{
				pre=tmp;
				tmp=0;
				ans+=pre;
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	memset(c,-1,sizeof(c));
	int T=read();
	while (T--) work();
	return 0;
}