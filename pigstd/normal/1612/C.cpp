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

const int M=110;
int n,a,b,p[M],vis[M];

int get(int x)
{
	int tl=1,tr=2e9,p=0;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (Mid*(Mid+1)/2<=x)p=Mid,tl=Mid+1;
		else tr=Mid-1;
	}return p;
}

signed main()
{
	WT
	{
		int k=read(),x=read();
		if (x>=k*k)cout<<2*k-1<<endl;
		else if (x>=k*(k+1)/2)
			cout<<2*k-get(k*k-x)-1<<endl;
		else cout<<get(x-1)+1<<endl;
	}
	return 0;
}