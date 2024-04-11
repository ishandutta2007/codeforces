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
	WT
	{
		int n=read();
		if (n==1)puts("a");
		else if (n%2==0)
		{
			for (int i=1;i<n/2;i++)cout<<'a';
			cout<<'b';
			for (int i=1;i<=n/2;i++)cout<<'a';
			puts("");
		}
		else
		{
			for (int i=1;i<=n/2;i++)cout<<'a';
			cout<<"bc";
			for (int i=1;i<n/2;i++)cout<<'a';
			puts("");
		}
	}
	return 0;
}