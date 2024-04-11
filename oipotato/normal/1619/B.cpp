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
int a[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		int len=(int)sqrt(n),ans=0;
		rep(i,len)
		{
			if((LL)i*i*i<=n)ans++;
			int x=i*i;
			int y=(int)pow(x,1./3);
			if(y*y*y==x)continue;
			y++;
			if(y*y*y==x)continue;
			ans++;
		}
		printf("%d\n",ans);
	}
    return 0;
}