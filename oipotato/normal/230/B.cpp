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
bool notp[1000010];
int prime[1000010],tot;
int main()
{
	notp[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!notp[i])prime[++tot]=i;
		for(int j=1;j<=tot&&(LL)prime[j]*i<=1000000;j++)
		{
			notp[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
	int n;scanf("%d",&n);
	rep(i,n)
	{
		LL x;scanf("%lld",&x);
		int tmp=(int)floor(sqrt(x));
		if((LL)tmp*tmp!=x)puts("NO");
		else puts(notp[tmp]?"NO":"YES");
	}
    return 0;
}