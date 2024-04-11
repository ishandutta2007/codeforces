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
const int MOD=(int)1e9+7;
const int inv2=(MOD+1)/2;
int n,s[2000010],fac[500010];
int main()
{
	scanf("%d",&n);
	fac[0]=1;
	rep(i,n)fac[i]=(LL)fac[i-1]*i%MOD;
	int m=(int)1e6,del=(int)1e6;
	rep(i,n)
	{
		int x;scanf("%d",&x);x--;
		s[-x+del]++;
		s[x+2+del]--;
	}
	for(int i=-m+2;i<=m;i++)s[i+del]+=s[i-2+del];
	int ans=0,cnt=1,now=0;
	for(int i=-m;i<=m;i++)
	{
		ans=(ans+(LL)(now+1+now+s[i+del])*s[i+del]%MOD*inv2%MOD*(MOD+i))%MOD;
		(now+=s[i+del])%=MOD;
		cnt=(LL)cnt*fac[s[i+del]]%MOD;
	}
	printf("%d %d\n",ans,cnt);
    return 0;
}