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

const int inf=1e18;
const int M=2e5+10;
int n,k,a[M],b[M],sum[M],t[M<<1];

bool check(int x)
{
	for (int i=1;i<=n;i++)
		b[i]=a[i]>=x?1:-1,sum[i]=sum[i-1]+b[i];
	for (int i=0;i<=2*n;i++)t[i]=inf;
	for (int i=n;i>=0;i--)t[sum[i]+n]=i;
	for (int i=1;i<=2*n;i++)t[i]=min(t[i],t[i-1]);
	for (int i=1;i<=n;i++)
		if (sum[i]+n-1>=0) 
			if (i-t[sum[i]+n-1]>=k)return 1;
	return 0;
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)a[i]=read();
	int tl=1,tr=n,ans=0;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (check(Mid))tl=Mid+1,ans=Mid;
		else tr=Mid-1;
	}cout<<ans<<endl;
	return 0;
}