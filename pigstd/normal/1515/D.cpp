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

const int M=2e5+10;
int n,l,r,a[M],t[M];

signed main()
{
	WT
	{
		n=read(),l=read(),r=read();
		for (int i=1;i<=n;i++)t[i]=0;
		for (int i=1;i<=l;i++)a[i]=read(),t[a[i]]++;
		for (int i=l+1;i<=n;i++)a[i]=read(),t[a[i]]--;
		sort(t+1,t+1+n);int cnt1=0,cnt2=0,sum1=0,sum2=0;
		for (int i=1;i<=n;i++)
			if (t[i]<0)cnt1+=abs(t[i])%2,sum1+=abs(t[i])/2;
			else cnt2+=abs(t[i])%2,sum2+=abs(t[i])/2;
		int ans=max(cnt1,cnt2)-min(abs(cnt1-cnt2)/2,(cnt1>cnt2)?sum2:sum1);
		ans+=sum1+sum2;
		cout<<ans<<endl;
	}
	return 0;
}