#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int T,a[5];

signed main()
{
	T=read();
	while(T--)
	{
		for (int i=1;i<=4;i++)a[i]=read();
		sort(a+1,a+5);cout<<a[1]*a[3]<<endl;
	}return 0;
}