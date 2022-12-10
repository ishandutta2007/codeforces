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

#define N 505
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,a[4][N][N],c[N][N],id[4],ans;

char s[N];

int main()
{
		scanf("%d",&n);
		for (k=0;k<4;++k)
			for (i=1;i<=n;++i)
			{
				scanf("%s",s+1);
				for (j=1;j<=n;++j)
						a[k][i][j]=s[j]-'0';
			}
		for (i=0;i<4;++i) id[i]=i; ans=10000000;
		for (int T=0;T<24;++T)
		{
			for (i=1;i<=n;++i)
				for (j=1;j<=n;++j)
					c[i][j]=a[id[0]][i][j],
					c[i+n][j]=a[id[1]][i][j],
					c[i][j+n]=a[id[2]][i][j],
					c[i+n][j+n]=a[id[3]][i][j];
			int now=0,sum=0,pre=1;
			for (i=1;i<=2*n;++i)
			{
				pre=now;
				for (j=1;j<=2*n;++j)
				{
						if (pre!=c[i][j]) ++sum;
						pre^=1;
				}
				now^=1;
			}
			ans=min(ans,sum);
			sum=0; now=1;
			for (i=1;i<=2*n;++i)
			{
				pre=now;
				for (j=1;j<=2*n;++j)
				{
						if (pre!=c[i][j]) ++sum;
						pre^=1;
				}
				now^=1;
			}
			ans=min(ans,sum);
			next_permutation(id,id+4);
		}
		printf("%d\n",ans);
		
}