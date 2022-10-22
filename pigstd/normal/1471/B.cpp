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
int n,x;
int a[M],b[M];

signed main()
{
	WT
	{
		n=read(),x=read();b[0]=1e18;int ans=0,minp=0;
		for (int i=1;i<=n;i++)
		{
			a[i]=read();int res=x;b[i]=0;
			while(a[i]%res==0)
				res*=x,b[i]++;
			if (b[i]<b[minp])minp=i;
		}int sum1=0,sum2=0;
		for (int i=1;i<=n;i++)sum1+=a[i];
		ans=sum1*(b[minp]+1);
		for (int i=1;i<minp;i++)sum2+=a[i];
		ans+=sum2;
		cout<<ans<<endl;
	}
	return 0;
}