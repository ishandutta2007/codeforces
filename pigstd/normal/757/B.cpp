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

const int M=1e5+10;
int a[M],t[M],n,ans=1;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)t[a[i]=read()]++;
	for (int i=2;i<=1e5;i++)
	{
		int sum=0;
		for (int j=i;j<=1e5;j+=i)
			sum+=t[j];
		ans=max(ans,sum);
	}cout<<ans<<endl;
	return 0;
}