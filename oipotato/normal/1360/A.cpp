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
int sqr(int x){return x*x;}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int a,b;scanf("%d%d",&a,&b);
		printf("%d\n",sqr(min(a+b,min(max(2*a,b),max(a,2*b)))));
	}
    return 0;
}