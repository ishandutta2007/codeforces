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

int i,j,m,n,p,k,a[N];

int main()
{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;++i) scanf("%d",&a[i]),a[0]=max(a[0],a[i]); a[0]+=m;
		for (;m--;)
		{
				int id=1;
				for (i=1;i<=n;++i) if (a[i]<a[id]) id=i;
				a[id]++;
		}
		for (i=1;i<=n;++i) a[n+1]=max(a[n+1],a[i]);
		printf("%d %d\n",a[n+1],a[0]);
}