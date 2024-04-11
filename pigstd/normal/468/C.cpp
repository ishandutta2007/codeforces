#include<bits/stdc++.h>
#define int long long
using namespace std;

int a,p=1e18;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	a=read();p%=a;p=p*9%a;p=p*9%a;
	cout<<a-p<<' '<<(int)(a+1e18-p-1);
	return 0;
}