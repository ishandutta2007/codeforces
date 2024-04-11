#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=998244353;
int S[2010][2010];
int mypow(int x,int n){int res=1;for(;n;n>>=1,x=(LL)x*x%MOD)if(n&1)res=(LL)res*x%MOD;return res;}
int main()
{
	S[0][0]=1;
	rep(i,2000)rep(j,2000)S[i][j]=(S[i-1][j-1]+(LL)j*S[i-1][j])%MOD;
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int ans=0,C=mypow(m,n),inv=mypow(m,MOD-2);
		rep(i,k)C=(LL)C*((m+1)/2)%MOD*inv%MOD*(n-i+1)%MOD,ans=(ans+(LL)C*S[k][i])%MOD;
		printf("%d\n",ans);
	}
    return 0;
}