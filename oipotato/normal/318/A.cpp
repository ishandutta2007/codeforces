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
int main()
{
	LL n,k;
	scanf("%lld%lld",&n,&k);
	LL tmp=(n+1)/2;
	if(k<=tmp)printf("%lld\n",2*k-1);
	else printf("%lld\n",(k-tmp)*2);
    return 0;
}