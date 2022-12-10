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

char c[N],s[N];

int i,j,m,n,p,k;

int main()
{
		scanf("%s",c+1);
		n=strlen(c+1); j=(n+1)/2;
		for (i=1;i<=n;++i)
		{
				if (i&1)
				{
						while (c[j]==0) --j;
						s[++m]=c[j];
						c[j]=0;
				}
				else
				{
						while (c[j]==0) ++j;
						s[++m]=c[j];
						c[j]=0;
				}
		}
		printf("%s\n",s+1); 
}