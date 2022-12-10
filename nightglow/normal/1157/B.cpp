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

int i,j,m,n,p,k,f[105];

char c[N];

int main()
{
		scanf("%d",&n);
		scanf("%s",c+1);
		for (i=1;i<=9;++i) scanf("%d",&f[i]);
		for (i=1;i<=n;++i)
		{
				int ch=c[i]-'0';
				if (ch<f[ch]) break;
		}
		for (j=min(n+1,i+1);j<=n;++j)
		{
				int ch=c[j]-'0';
				if (ch>f[ch]) break;
		}
		for (k=i;k<j;++k) c[k]=f[c[k]-'0']+'0';
		printf("%s\n",c+1);
}