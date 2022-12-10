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

int i,j,m,n,p,k,a[8];

char c[10];

int main()
{
		memset(a,60,sizeof(a)); a[0]=0;
		scanf("%d",&n);  
		for (;n--;)
		{
				scanf("%d",&k);
				scanf("%s",c+1);
				int len=strlen(c+1),w=0;
				for (i=1;i<=len;++i) w|=(1<<c[i]-'A');
				for (i=0;i<8;++i) a[i|w]=min(a[i|w],a[i]+k);
		}
		if (a[7]>1e8) puts("-1");
		else printf("%d\n",a[7]);
}