#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=5010;
int T,n,ans,a[M],t[M];

signed main()
{
	T=read();
	while(T--)
	{
		n=read();ans=0;
		for (int i=1;i<=n;i++)a[i]=read(),t[i]=0;
		for (int i=1;i<n;i++)
		{
			int cnt=0;
			if (a[i]+i>=n)
				cnt+=a[i]+i-n,a[i]=n-i;
			for (int j=i+2;j<=i+a[i];j++)
				t[j]++,cnt++;
			cnt-=t[i];
			if (cnt<0)
				t[i+1]+=-cnt,cnt=0;
			ans+=cnt;
		}
		ans+=max(a[n]-1-t[n],0ll);
		cout<<ans<<endl;
	}
	return 0;
}