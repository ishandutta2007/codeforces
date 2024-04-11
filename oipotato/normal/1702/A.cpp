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
		int m;scanf("%d",&m);
		LL x=10;
		for(;x<=m;x*=10);
		printf("%d\n",m-x/10);
	}
    return 0;
}