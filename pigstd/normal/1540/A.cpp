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
int a[M],n;

signed main()
{
	WT
	{
		n=read();int ans=0,sum=0;
		for (int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);
		for (int i=2;i<=n;i++)
			sum+=(a[i-1]-a[i])*(i-1),ans+=sum;
		ans+=a[n];
		cout<<ans<<endl;
	}
	return 0;
}