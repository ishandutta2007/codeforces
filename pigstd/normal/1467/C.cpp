#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=3e5+10;
int n1,n2,n3,a1[M],a2[M],a3[M],sum1,sum2,sum3,ans,sum;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n1=read(),n2=read(),n3=read();
	for (int i=1;i<=n1;i++)a1[i]=read(),sum1+=a1[i];
	for (int i=1;i<=n2;i++)a2[i]=read(),sum2+=a2[i];
	for (int i=1;i<=n3;i++)a3[i]=read(),sum3+=a3[i];
	sum=sum1+sum2+sum3;
	ans=max(ans,sum1+sum2-sum3);sort(a1+1,a1+n1+1);
	ans=max(ans,sum1-sum2+sum3);sort(a2+1,a2+n2+1);
	ans=max(ans,sum2+sum3-sum1);sort(a3+1,a3+n3+1);
	ans=max(ans,sum-2*min(a1[1]+a2[1],min(a1[1]+a3[1],a2[1]+a3[1])));
	cout<<ans;
	return 0;
}