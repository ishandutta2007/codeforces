#include<bits/stdc++.h>
#define int unsigned int
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=200;
int n,p,q,ans,C[M],a[M],b[M];

signed main()
{
	n=read(),p=read(),q=read();p=min(p,n-1);
	C[0]=1;
	for (int i=1;i<=p;i++)
	{
		for (int j=1;j<=i;j++)
			a[j]=n-j+1,b[j]=j;
		for (int j=1;j<=i;j++)
			while(b[j]!=1)
				for (int k=1;k<=i;k++)
				{
					int d=__gcd(a[k],b[j]);
					a[k]/=d,b[j]/=d;
				}
		C[i]=1;
		for (int j=1;j<=i;j++)
			C[i]=C[i]*a[j];
	}
	for (int i=1;i<=q;i++)
	{
		int res=1,sum=0;
		for (int j=0;j<=p;j++)
		{
			sum+=C[j]*res;
			res*=i;
		}
		sum*=i;
		ans^=sum;
	}
	cout<<ans<<endl;
	return 0;
}