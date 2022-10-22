#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,a[M*2],sum,ans;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=a[i+n]=read();
	for (int i=1;i<=n*2;i++)
	{
		if (a[i]==0)sum=0;
		else sum++;
		ans=max(ans,sum);
	 } cout<<ans<<endl;
	return 0;
}