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

int a[105];

signed main()
{
	WT
	{
		int n=read(),minn=1e18,res=0;
		for (int i=1;i<=n;i++)a[i]=read(),minn=min(minn,a[i]);
		for (int i=1;i<=n;i++)if (a[i]!=minn)res++;
		cout<<res<<'\n';
	}
	return 0;
}