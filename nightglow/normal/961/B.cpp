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

int i,j,m,n,p,k,a[N],x,ans,b[N],Ans;

int main()
{
		scanf("%d%d",&n,&k);
		for (i=1;i<=n;++i)
		{
				scanf("%d",&a[i]); 
		}
		for (i=1;i<=n;++i)
		{
				scanf("%d",&x);
				if (x==1) ans+=a[i],b[i]=b[i-1];
				else b[i]=b[i-1]+a[i];
		}
		for (i=1;i<=n-k+1;++i) Ans=max(Ans,ans+b[i+k-1]-b[i-1]);
		printf("%d\n",Ans);
}