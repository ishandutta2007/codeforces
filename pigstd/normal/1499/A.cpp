#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int T,n,k1,k2,w,h;

signed main()
{
	T=read();
	while(T--)
	{
		n=read(),k1=read(),k2=read(),w=read(),h=read();
		int w1=(k1+k2)/2,h1=(2*n-k1-k2)/2;
		if (w1>=w&&h1>=h)puts("YES");
		else puts("NO");
	}
	return 0;
}