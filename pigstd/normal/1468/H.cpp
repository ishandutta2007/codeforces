#include<bits/stdc++.h>
#define int long long
#define pb push_back
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
int k,n,m,b[M],a[M],t[M];

signed main()
{
	WT
	{
		n=read(),k=read(),m=read();
		for (int i=1;i<=n;i++)t[i]=0;
		for (int i=1;i<=m;i++)a[i]=read(),t[a[i]]=1;
		if ((n-m)%(k-1)!=0){puts("NO");continue;}
		int f=0,cnt=0;k/=2;
		for (int i=1;i<=n;i++)
		{
			if (!t[i])cnt++;
			else if (cnt>=k&&cnt<=n-m-k){f=1;break;}
		}
		if (f)puts("YES");
		else puts("NO");
	}
	return 0;
}