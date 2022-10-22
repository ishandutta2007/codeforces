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

int a[105];

signed main()
{
	WT
	{
		int n=read(),k=read();
		if (n&1)
		{
			int x=k+(k-1)/(n/2);
			cout<<(1+(x-1)%n)<<endl;
		}
		else
		{
			int x=1+(k-1)%n;
			cout<<x<<endl;
		}
	}
	return 0;
}