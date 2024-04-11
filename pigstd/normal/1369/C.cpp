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
int n,k,a[M],b[M];

bool cmp(int a,int b){return a>b;}

signed main()
{
	WT
	{
		n=read(),k=read();
		for (int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=k;i++)b[i]=read();
		sort(b+1,b+1+k);int sum=k,ans=0;
		for (int i=1;i<=k;i++)
			ans+=a[i]+(b[i]==1?a[i]:0);
		for (int i=1;i<=k;i++)
		{
			b[i]--;if (b[i]==0)continue;
			ans+=a[sum+b[i]],sum+=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}