#include<bits/stdc++.h>
#define WT int T=read();while(T--)
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2020;
int ans[M],cnt;

signed main()
{
	WT
	{
		int n=read();cnt=0;
		if (n&1){puts("-1");continue;}
		for (int i=60;i>=1;i--)
		{
			int x=1ll<<(i+1);x-=2;
			while(n>=x)
			{
				n-=x;ans[++cnt]=1;
				for (int j=1;j<i;j++)
					ans[++cnt]=0;
			}
		}cout<<cnt<<endl;
		for (int i=1;i<=cnt;i++)
			cout<<ans[i]<<' ';puts("");
	}
	return 0;
}