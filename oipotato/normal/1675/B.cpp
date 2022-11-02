#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
typedef unsigned long long ULL;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,a[33];scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		bool flag=1;
		int ans=0;
		for(int i=n-1;i;i--)
		{
			for(;a[i]&&a[i]>=a[i+1];a[i]/=2,ans++);
			if(a[i]>=a[i+1]){flag=0;break;}
		}
		if(!flag)puts("-1");else printf("%d\n",ans);
	}
    return 0;
}