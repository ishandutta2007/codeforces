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
LL f[100010];
int cnt[100010],n;
int main()
{
	scanf("%d",&n);
	rep(i,n){int x;scanf("%d",&x);cnt[x]++;}
	f[1]=cnt[1];
	rep(i,100000)
	{
		if(i==1)continue;
		f[i]=f[i-2]+(LL)cnt[i]*i;
		f[i]=max(f[i],f[i-1]);
	}
	printf("%lld\n",f[100000]);
    return 0;
}