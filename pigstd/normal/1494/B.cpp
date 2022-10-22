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

int n,a,b,c,d;

bool check(int a,int c,int b,int d)
{
	if (a==n)b--,d--;
	if (c==n)b--,d--;
	if (a==n-1)
	{
		if (b<d)d--;
		else b--;
	}
	if (c==n-1)
	{
		if (b<d)d--;
		else b--;
	}
	return b>=0&&d>=0;
}

signed main()
{
	WT
	{
		n=read(),a=read(),b=read(),c=read(),d=read();
		if (a<c)swap(a,c);if (b<d)swap(b,d);
		if (check(a,c,b,d)&&check(b,d,a,c))YES
		else NO
	}
	return 0;
}