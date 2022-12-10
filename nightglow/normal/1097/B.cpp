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

int i,j,m,n,p,k,a[105],flag;

void dfs(int pt,int x)
{
		if (x>n) 
		{
				if (pt%360==0) flag=1;
		}
		else
		{
				dfs(pt+a[x],x+1);
				dfs(pt-a[x],x+1);
		}
}

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) scanf("%d",&a[i]);
		dfs(0,1);
		if (flag) printf("YES\n");
		else puts("NO"); 
}