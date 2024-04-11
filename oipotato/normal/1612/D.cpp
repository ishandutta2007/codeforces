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
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
bool check(LL a,LL b,LL x)
{
	if(!a||x>b)return 0;
	if((b-x)%a==0)return 1;
	return check(b%a,a,x);
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		LL a,b,x;
		scanf("%lld%lld%lld",&a,&b,&x);
		if(a>b)swap(a,b);
		if(check(a,b,x))puts("YES");else puts("NO");
	}
    return 0;
}