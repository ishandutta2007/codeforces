#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,n;

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
		int n=read();
		if (n==1)puts("9");
		else if (n==2) puts("98");
		else
		{
			cout<<"989";
			for (int i=4;i<=n;i++)
				cout<<(i-4)%10;
			puts("");
		}
		
	}
	return 0;
}