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

int i,j,m,n,p,k,ans=(int)2e9;

int main()
{
		scanf("%d%d",&n,&k);
		for (i=1;i<k;++i) if (n%i==0) ans=min(ans,(n/i)*k+i);
		printf("%d\n",ans); 
}