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
int n,a[M],b[M],t1[M],t2[M];

signed main()
{
	WT
	{
		n=read();
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		for (int i=1;i<=n;i++)a[i]=b[i]=read(),t1[a[i]]+=i&1;
		sort(b+1,b+1+n);
		for (int i=1;i<=n;i++)t2[b[i]]+=i&1;
		int f=1;
		for (int i=1;i<=1e5;i++)
			if (t1[i]!=t2[i])f=0;
		if (f)YES
		else NO
	}
	return 0;
}