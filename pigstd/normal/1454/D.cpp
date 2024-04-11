#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e5+10;
int prime[M],cnt,T,n;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

bool is_prime(int k)
{
	for (int i=2;i*i<=k;i++)
		if (k%i==0)return 0;
	return 1;
}

signed main()
{
	for (int i=2;i<=1e5;i++)
		if (is_prime(i))prime[++cnt]=i;
	T=read();
	while(T--)
	{
		n=read();int maxn=0,p=-1,l=n;
		for (int i=1;i<=cnt&&prime[i]<=n;i++)
		{
			int k=0;
			while(n%prime[i]==0)
				n/=prime[i],k++;
			if (k>maxn)maxn=k,p=prime[i];
		}
		if (p==-1)
		{
			printf("1\n%lld\n",n);
			continue;
		}
		printf("%lld\n",maxn);
		for (int i=1;i<maxn;i++)printf("%lld ",p),l/=p;
		printf("%lld\n",l);
	}
	return 0;
}