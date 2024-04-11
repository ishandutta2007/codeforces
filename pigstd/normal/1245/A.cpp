#include<bits/stdc++.h>
#define int long long
using namespace std;


const int M=2e5+10;
int T,a,b;

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
		a=read(),b=read();
		if (__gcd(a,b)==1)puts("Finite");
		else puts("Infinite");
	}return 0;
}