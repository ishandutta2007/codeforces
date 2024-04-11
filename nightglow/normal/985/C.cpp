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

int i,j,m,n,p,k,a[N],v;

long long ans;

int main()
{
		scanf("%d%d%d",&n,&k,&v);
		for (i=1;i<=n*k;++i) scanf("%d",&a[i]);
		sort(a+1,a+n*k+1);
		if (a[n]-a[1]>v) puts("0");
		else
		{
				for (i=1;i<=n*k;++i) if (a[i]-a[1]>v) break;
				int rest=n-1,nowused=k-1;
				for (j=2;j<=n*k;++j)
				{
						if (rest&&i-j==rest) rest--,ans+=a[j],nowused+=k-1;
						else if (nowused==0) rest--,ans+=a[j],nowused+=k-1;
						else nowused--; 
				}
				printf("%I64d\n",ans+a[1]);
		}
		 
}