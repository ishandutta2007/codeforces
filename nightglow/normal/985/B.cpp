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

int i,j,m,n,p,k,t[N];

char c[2005][2005];

int main()
{
		scanf("%d%d",&n,&m);
		for (i=0;i<n;++i)
		{
				scanf("%s",c[i]);
				for (j=0;j<m;++j) if (c[i][j]=='1') t[j]++;
		}
		for (i=0;i<m;++i) if (!t[i]) break;
		if (i<m) puts("NO");
		else
		{
				for (i=0;i<n;++i)
				{
						for (j=0;j<m;++j) if (c[i][j]=='1'&&t[j]==1) break;
						if (j==m) break;
				}
				if (i<n) puts("YES");
				else puts("NO");	 
		}
}