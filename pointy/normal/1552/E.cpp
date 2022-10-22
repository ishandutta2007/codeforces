// By: Little09
// Problem: E. Colors and Intervals
// Contest: Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/E
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
int a[N],c[N],ans[N][2],cnt,tot,p[N];

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
	for (int i=1;i<=n*m;i++) a[i]=read();
	int l=1,r=m-1;
	cnt=0;
	while (1)
	{
		if (l>n) break;
		if (r>n) r=n;
		mem(c);
		tot=0,cnt=0;
		for (int i=1;i<=n*m;i++)
		{
			if (c[a[i]]!=0)
			{
				if (ans[a[i]][0]==0)
				{
					++cnt;
					ans[a[i]][0]=c[a[i]];
					ans[a[i]][1]=i;
					for (int j=1;j<=tot;j++) c[p[j]]=0;
					tot=0;
					if (cnt>=r-l+1) break;
				}
				else c[a[i]]=i,p[++tot]=a[i];
			}
			else c[a[i]]=i,p[++tot]=a[i];
		}
		//cout << l << " " << r << endl;
		l=r+1,r=l+m-2;
		// for (int i=1;i<=n;i++)
		// {
			// printf("%d %d\n",ans[i][0],ans[i][1]);
		// }
		// cout << endl;
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	return 0;
}