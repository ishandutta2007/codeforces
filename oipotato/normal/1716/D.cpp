#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=998244353;
int f[2][200010],ans[200010],n,k;
int main()
{
	scanf("%d%d",&n,&k);
	f[0][0]=1;
	for(int i=0,sum=0;sum<=n;sum+=k+i,i++)
	{
		for(int j=k+i;j<=n;j++)(f[i&1][j]+=f[i&1][j-(k+i)])%=MOD;
		rep(j,n)(ans[j]+=f[i&1][j])%=MOD;
		memset(f[(i&1)^1],0,sizeof(f[(i&1)^1]));
		for(int j=k+i+2;j<=n;j++)f[(i&1)^1][j]=f[i&1][j-(k+i+1)];
	}
	rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}