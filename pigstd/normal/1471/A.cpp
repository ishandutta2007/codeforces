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

signed main()
{
	WT
	{
		int n=read(),x=read(),ans1=0,ans2=0;
		for (int i=1;i<=n;i++)
		{
			int u=read();ans1+=(u-1)/x+1,ans2+=u;
		}
		ans2=(ans2-1)/x+1;
		cout<<ans2<<' '<<ans1<<endl;
	}
	return 0;
}