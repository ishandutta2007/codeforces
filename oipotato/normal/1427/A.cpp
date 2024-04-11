#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<cassert>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define hash hsh
typedef long long LL;
int a[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		int sum=0;
		rep(i,n)scanf("%d",&a[i]),sum+=a[i];
		sort(a+1,a+n+1);
		if(sum==0)puts("NO");
		else
		{
			puts("YES");
			if(sum>0)reverse(a+1,a+n+1);
			rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
		}
	}
    return 0;
}