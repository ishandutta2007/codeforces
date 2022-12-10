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

int i,j,m,n,p,k,Ans[N],T;

int main()
{
		memset(Ans,-1,sizeof(Ans));
		for (i=180;i>=3;--i)
			for (j=1;j<=i-2;++j)
				if (180*j%i==0)
				   Ans[180*j/i]=i;
		Ans[179]=360;
		scanf("%d",&T);
		for (;T--;)
		{
				int x;
				scanf("%d",&x);
				printf("%d\n",Ans[x]);
		}
}