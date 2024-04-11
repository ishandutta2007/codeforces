#include<bits/stdc++.h>
#define int long long
using namespace std;

int T;

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
		int x=read(),y=read(),k=read();
		if ((k*y+k-1)%(x-1)==0)cout<<(k*y+k-1)/(x-1)+k<<endl;
		else cout<<(k*y+k-1)/(x-1)+k+1<<endl;
	}
	return 0;
}