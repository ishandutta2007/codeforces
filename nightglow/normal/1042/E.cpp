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

#define N 1005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

#define Mo 998244353

using namespace std;

int i,j,m,n,p,k;

int id[N*N],a[N*N],b[N*N],c[N*N],R,C,tot,prob,probt,w1,w2,w3,ans;

int cmp(int x,int y)
{
		return a[x]>a[y];
}

int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
				if (y&1) sum=1ll*sum*x%Mo;
				x=1ll*x*x%Mo;
		}
		return sum;
}

int main()
{
		 scanf("%d%d",&n,&m);
		 for (i=1;i<=n;++i)
		 	for (j=1;j<=m;++j)
		 	{
		 			++tot;
		 			id[tot]=tot;
		 			scanf("%d",&a[tot]);
		 			b[tot]=i;
		 			c[tot]=j;
		 	}
		scanf("%d%d",&R,&C);
		sort(id+1,id+tot+1,cmp);
		for (i=1;i<=tot;i=j)
		{
				for (j=i;j<=tot&&a[id[i]]==a[id[j]];++j);
				for (k=i;k<j;++k)
				{
						int p=id[k];
						int probt=0;
						if (b[p]==R&&c[p]==C) probt=1;
						else probt=prob;
						ans=(ans+w1)%Mo;
						ans=(ans+1ll*prob*(b[p]*b[p]+c[p]*c[p])%Mo)%Mo;
						ans=(ans-1ll*w2*b[p]%Mo+Mo)%Mo;
						ans=(ans-1ll*w3*c[p]%Mo+Mo)%Mo;
				}
				int wt=prob;
				for (k=i;k<j;++k)
				{
						int p=id[k];
						int probt=0;
						if (b[p]==R&&c[p]==C) probt=1;
						else probt=wt;
						probt=1ll*probt*power(tot-j+1,Mo-2)%Mo;
						prob=(prob+probt)%Mo;
						w1=(w1+1ll*(b[p]*b[p]+c[p]*c[p])*probt%Mo)%Mo;
						w2=(w2+2ll*probt*b[p]%Mo)%Mo;
						w3=(w3+2ll*probt*c[p]%Mo)%Mo; 
				}
		}
		printf("%d\n",ans); 
}