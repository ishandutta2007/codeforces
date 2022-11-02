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
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(b>=a)printf("%d\n",b);
		else if(c<=d)puts("-1");
		else
		{
			int tmp=(a-b-1)/(c-d)+1;
			printf("%lld\n",b+(LL)tmp*c);
		}
	}
    return 0;
}