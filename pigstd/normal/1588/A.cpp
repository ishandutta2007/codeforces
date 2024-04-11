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

const int M=1e5+10;
int n,a[M],b[M]; 

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=1;i<=n;i++)b[i]=read();
		sort(a+1,a+1+n);sort(b+1,b+1+n);int f=1;
		for (int i=1;i<=n;i++)
			if (b[i]!=a[i]&&b[i]!=a[i]+1)f=0;
		if (f)YES
		else NO
	}
	return 0;
}