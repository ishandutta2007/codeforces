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

signed main()
{
	WT{
		int x=read(),y=read();
		if ((x+y)&1)puts("-1 -1");
		else if (x&1)
			cout<<x/2+1<<' '<<y/2<<endl;
		else cout<<x/2<<' '<<y/2<<endl;
	}
	return 0;
}