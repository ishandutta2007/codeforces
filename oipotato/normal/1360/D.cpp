#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k;scanf("%d%d",&n,&k);
		int ans=n,len=(int)sqrt(n);
		rep(i,len)if(n%i==0)
		{
			if(i<=k)ans=min(ans,n/i);
			if(n/i<=k)ans=min(ans,i);
		}
		printf("%d\n",ans);
	}
    return 0;
}