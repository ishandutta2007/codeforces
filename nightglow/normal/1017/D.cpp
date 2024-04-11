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
#define M 10000005

#define ls tree[t].l
#define rs tree[t].r
#define Ls tree[t1].l
#define Rs tree[t1].r
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

#define Mo 1000000007

using namespace std;

long long ans;

int i,j,m,n,p,k,w[N],la,ne,q;

int f[64][64][1205];

char c[15];

int Count(int p)
{
		int i,sum=0;
		for (i=0;i<la;++i) if ((p&(1<<i))==0) sum+=w[i]; 
		return sum;
}

int Count2(int p)
{	
		int i,sum=0;
		for (i=0;i<ne;++i) if ((p&(1<<i))==0) sum+=w[i+la];
		return sum;
}

int main()
{
					scanf("%d%d%d",&n,&m,&q);
					for (i=0;i<n;++i) scanf("%d",&w[i]);
					la=n/2,ne=n-la;
					for (;m--;)
					{
							scanf("%s",c); int p=0;
							for (i=n-1;i>=0;--i) p=p*2+c[i]-'0';
							int g=p&((1<<la)-1);
							for (i=0;i<(1<<la);++i) f[i][p>>la][Count(i^g)]++;
					}
					for (i=0;i<(1<<la);++i)
						for (j=0;j<(1<<ne);++j)
							for (k=1;k<1205;++k)
								f[i][j][k]+=f[i][j][k-1];
					for (;q--;)
					{
							scanf("%s%d",c,&k);
							for (i=n-1;i>=0;--i) p=p*2+c[i]-'0';
							int g=p&((1<<la)-1),ans=0;
							for (i=0;i<(1<<ne);++i)
							{
									int rest=k-Count2((p>>la)^i);
									if (rest<0) continue;
									ans+=f[g][i][rest];
							}
							printf("%d\n",ans);
					}
}