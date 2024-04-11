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

const int M=1e6+10;
int f[M],n,k;

signed main()
{
	WT
	{
		n=read(),k=read();
		if (k%3==0)
		{
			n%=(k+1);
			if (n!=k&&n%3==0)puts("Bob");
			else puts("Alice");
		}
		else
		{
			if (n%3==0)puts("Bob");
			else puts("Alice");
		}
	}
	return 0;
}
/*

*/