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
		int n=read(),k=read();
		if (n&1)cout<<1<<' '<<n/2<<' '<<n/2<<endl;
		else if (n%4==2) cout<<2<<' '<<n/2-1<<' '<<n/2-1<<endl;
		else if (n==4)puts("1 1 2");
		else cout<<n/2<<' '<<n/4<<' '<<n/4<<endl;
	}
	return 0;
}