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

int i,j,m,n,p,k,s,deg[N],cnt;

int main()
{
		scanf("%d%d",&n,&s);
		for (i=1;i<n;++i)
		{
				int x,y;
				scanf("%d%d",&x,&y);
				deg[x]++;deg[y]++; 
		}
		for (i=1;i<=n;++i) if (deg[i]==1) ++cnt;
		printf("%.10lf\n",2.*s/cnt);
}