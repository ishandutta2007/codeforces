#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int T,n,a[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

bool cmp(int a,int b){return a>b;}

signed main()
{
	T=read();
	while(T--)
	{
		int sum1=0,sum2=0;
		n=read();
		for (int i=1;i<=n;i++)
			a[i]=read();
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=n;i++)
		{
			if (i&1ll)
			{
				if (a[i]%2==0)sum1+=a[i];
			}
			else
			{
				if (a[i]%2==1)sum2+=a[i];
			}
		}
		if (sum1==sum2)puts("Tie");
		if (sum1>sum2)puts("Alice");
		if (sum1<sum2)puts("Bob");
	}
	return 0;
}