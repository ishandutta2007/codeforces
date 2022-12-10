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

int i,j,m,n,p,k,a[N],x;

int main()
{
		scanf("%d%d",&n,&m);
		for (i=1;i<=m;++i)
		{
				scanf("%d",&x);
				a[x]++; 
		}
		for (i=1;i<=n;++i) a[1]=min(a[1],a[i]);
		printf("%d\n",a[1]);
}