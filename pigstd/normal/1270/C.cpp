#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,sum1,sum2;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	T=read();
	while(T--)
	{
		int n=read();sum1=sum2=0;
		for (int i=1;i<=n;i++)
		{
			int a=read();
			sum1+=a,sum2^=a;
		}
		cout<<2<<endl<<sum2<<' '<<sum1+sum2<<endl;
	}
	return 0;
}