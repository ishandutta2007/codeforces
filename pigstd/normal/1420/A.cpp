#include<bits/stdc++.h>
#define WT int T=read();while(T--)
#define int long long
#define pb push_back
#define YES puts("YES")
#define NO puts("NO")
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}



signed main()
{
	WT
	{
		int n=read(),f=1,la=1e18;
		for (int i=1;i<=n;i++)
		{
			int x=read();
			if (x>=la)f=0;
			la=x;
		}if (!f)YES
		;else NO;
	}
	return 0;
}