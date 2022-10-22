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

const int M=110;
int n,k,a[M];

signed main()
{
	WT
	{
		n=read(),k=read();
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=1;i<=n-1;i++)
		{
			if (k==0)break;
			if (a[i]<=k)
				a[n]+=a[i],k-=a[i],a[i]=0;
			else a[n]+=k,a[i]-=k,k=0;
		}
		for (int i=1;i<=n;i++)
			cout<<a[i]<<' ';
		puts("");
	}
	return 0;
}