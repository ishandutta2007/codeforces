#include<bits/stdc++.h>
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

const int inf=1e18;
const int M=1e5+10;
int T,n,a[M],sum1,sum2;
int s1[M],s2[M],na;

bool cmp(int a,int b){return a>b;}

signed main()
{
	T=read();
	while(T--)
	{
		n=read();int ans=inf;
		sum1=n-n/2,sum2=n/2;
		for (int i=1;i<=n;i++)
			a[i]=read(); 
//		for (int i=1;i<=sum1;i++)cout<<a1[i]<<' ';
//		for (int i=1;i<=sum2;i++)cout<<a2[i]<<' ';
//		sort(a1+1,a1+1+sum1,cmp);
//		sort(a2+1,a2+1+sum2,cmp);
		ans=na=n*a[1]+n*a[2];
		int min1=a[1],min2=a[2];
		for (int i=3;i<=n;i++)
		{
			if (i&1)
			{
				int nsum=(i+1)/2;
				if (a[i]>=min1)
					na+=a[i]-min1;
				else na-=(n-nsum+1)*min1,na+=a[i]*(n-nsum+1),min1=a[i];
			}
			else
			{
				int nsum=i/2;
				if (a[i]>=min2)
					na+=a[i]-min2;
				else na-=(n-nsum+1)*min2,na+=a[i]*(n-nsum+1),min2=a[i];
			}
			ans=min(ans,na);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
3
2 3 1
*/