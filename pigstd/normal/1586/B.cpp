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
int n,m,f[M];

signed main()
{
	WT
	{
		n=read(),m=read();
		for (int i=1;i<=n;i++)f[i]=0;
		for (int i=1;i<=m;i++)
		{
			int a=read(),b=read(),c=read();
			f[b]++;
		}int p=-1;
		for (int i=1;i<=n;i++)
			if (f[i]==0){p=i;break;}
		for (int i=1;i<=n;i++)
			if (p!=i)printf("%lld %lld\n",i,p);
	}
	return 0;
}