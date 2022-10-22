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
int ans,n,a[M];

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		ans+=a[i]*(n-a[i]+1);
	}
	for (int i=2;i<=n;i++)
		ans-=min(a[i],a[i-1])*(n-max(a[i],a[i-1])+1);
	cout<<ans<<endl;
	return 0;
}
/*

*/