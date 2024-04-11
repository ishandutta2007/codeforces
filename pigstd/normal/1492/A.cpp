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

int f(int a,int b)
{
	b%=a;if (!b)return 0;
	return a-b;
}

signed main()
{
	WT
	{
		int p=read(),a=read(),b=read(),c=read();
		cout<<min(f(a,p),min(f(b,p),f(c,p)))<<endl;;
	}
	return 0;
}
/*

*/