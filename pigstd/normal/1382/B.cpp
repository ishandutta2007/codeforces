#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

const int M=1e5+10;
int n,m,a[M],b[M],t[M];

signed main()
{
	WT
	{
		n=read();int st;
		for (int i=1;i<=n;i++)a[i]=read();
		st=1;
		for (int i=n-1;i>=1;i--)
		{
			if (st)
			{
				if (a[i]==1)st=0;
				else st=1;
			}
			else st=1;
		}
		if (st)puts("First");
		else puts("Second");
	}return 0;
}