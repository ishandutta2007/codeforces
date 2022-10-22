//AFO countdown:8 Days
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=50010;
int n,p[M][7];

int check(int x)
{
	for (int i=1;i<=n;i++)
	{
		int res=0;
		for (int j=1;j<=5;j++)
			res+=p[x][j]<=p[i][j];
		if (res<=2)return 0;
	}return 1;
}

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<=n;i++)
			for (int j=1;j<=5;j++)
				p[i][j]=read();int f=1;
		int now=1;
		for (int i=2;i<=n;i++)
		{
			int res=0;
			for (int j=1;j<=5;j++)
				res+=p[now][j]<p[i][j];
			if (res<=2)now=i;
		}
		if (check(now))cout<<now<<endl;
		else puts("-1");
	}
	return 0;
}