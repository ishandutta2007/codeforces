#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

const int M=55;
int n,a[M];

signed main()
{
	WT
	{
		n=read();int f1=1;
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			if (a[i]!=i)f1=0;
		}if (f1){puts("0");continue;}
		if (a[1]==1||a[n]==n)puts("1");
		else if (a[1]==n&&a[n]==1)puts("3");
		else puts("2");
	}
	return 0;
}