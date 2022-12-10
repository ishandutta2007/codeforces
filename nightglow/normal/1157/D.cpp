#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,p,k,a[N];

long long n;

int main()
{
		scanf("%lld%d",&n,&k);
		for (i=1;i<=k;++i) a[i]=i,n-=i;
		if (n<0)
		{
				puts("NO");
				return 0;
		}
		else
		{
				for (i=1;i<=k;++i) a[i]+=n/k;
				n%=k;
				if (a[1]!=1||n!=k-1||k==1)
				{
						for (i=k;i>=k-n+1;--i) a[i]++;
				}
				else if (k>=4)
				{
						a[k]++;
						for (i=k;i>=3;--i) a[i]++; 
				}
				else 
				{
						puts("NO");
						return 0;
				}
		}
		puts("YES");
		for (i=1;i<=k;++i) printf("%d ",a[i]);
}