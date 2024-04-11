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

int check(int x)
{
	int y=sqrt(x);
	return y*y==x;
}

signed main()
{
	WT
	{
		int x=read();
		if (x&1)NO
		else if (check(x/2))YES
		else if (x%4==0&&check(x/4))YES
		else NO
	}
	return 0;
}