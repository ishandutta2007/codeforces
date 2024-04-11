#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,w,h,n;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	T=read();
	while(T--)
	{
		w=read(),h=read(),n=read();
		w*=h;
		int cnt=0;
		while(w%2==0)w/=2,cnt++;
		if ((1ll<<cnt)>=n)puts("YES");
		else puts("NO");
	}
	return 0;
}