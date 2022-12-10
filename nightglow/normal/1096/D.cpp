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

char s[4]={'h','a','r','d'};

int i,j,m,n,p,k,a[N];

char c[N];

long long f[N][5];

int main()
{
		scanf("%d",&n);
		scanf("%s",c+1);
		for (i=1;i<=n;++i) scanf("%d",&a[i]);
		memset(f,60,sizeof(f));
		f[0][0]=0;
		for (i=1;i<=n;++i)
		{
				for (j=0;j<4;++j)
				{
						f[i][j]=min(f[i][j],f[i-1][j]+a[i]);
						if (s[j]==c[i]) f[i][j+1]=min(f[i][j+1],f[i-1][j]);
						else f[i][j]=min(f[i][j],f[i-1][j]);
				}
		}
		cout<<min(f[n][0],min(f[n][1],min(f[n][2],f[n][3])))<<endl;
}