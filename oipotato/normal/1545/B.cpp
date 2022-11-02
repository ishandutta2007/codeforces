#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=998244353;
int n,fac[100010],inv[100010];
char s[100010];
int mypow(int x,int n){int res=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)res=1ll*res*x%MOD;return res;}
int C(int n,int m){return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
int main()
{
	int T;
	fac[0]=1;
	rep(i,100000)fac[i]=1ll*fac[i-1]*i%MOD;
	inv[100000]=mypow(fac[100000],MOD-2);
	for(int i=99999;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%MOD;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int cnt=0,m=0;
		rep(i,n)if(s[i]=='0')cnt++;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')continue;
			int j=i;
			for(;j<=n&&s[j]=='1';j++);
			m+=(j-i)/2;
			i=j;
		}
		printf("%d\n",C(cnt+m,m));
	}
    return 0;
}