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
		int n;scanf("%d",&n);
		int a=n/3,b,c;
		for(;;)
		{
			a++;
			c=1;b=n-a-1;
			if(b>=a)b=a-1,c=n-a-b;
			if(c>=1&&c<b)break;
		}
		printf("%d %d %d\n",b,a,c);
	}
    return 0;
}