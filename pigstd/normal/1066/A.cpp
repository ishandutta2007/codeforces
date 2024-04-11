#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e6+10;
int T,L,v,l,r;

signed main()
{
	T=read();
	while(T--)
	{
		L=read(),v=read(),l=read(),r=read();
		int ans=L/v;
		ans-=r/v,ans+=(l-1)/v;
		cout<<ans<<endl;
	}
	return 0;
}