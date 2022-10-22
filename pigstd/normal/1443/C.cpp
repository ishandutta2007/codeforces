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

const int M=2e5+10;
int n,a[M],b[M];

bool check(int x)
{
	int sum=0;
	for (int i=1;i<=n;i++)
		if (a[i]>x)sum+=b[i];
	return sum<=x;
}

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=1;i<=n;i++)b[i]=read();
		int tl=0,tr=1e18,p;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (check(Mid))tr=Mid-1,p=Mid;
			else tl=Mid+1;
		}cout<<p<<endl;
	}
	return 0;
}