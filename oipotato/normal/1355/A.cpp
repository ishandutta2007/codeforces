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
void work(LL&a)
{
	LL mn=9,mx=0;
	LL x=a;
	for(;x;mn=min(mn,x%10),mx=max(mx,x%10),x/=10);
	a+=mn*mx;
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		LL a,k;scanf("%lld%lld",&a,&k);k--;
		rep(i,k)
		{
			LL na=a;work(a);
			if(na==a)break;
		}
		printf("%lld\n",a);
	}
    return 0;
}