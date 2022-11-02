#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int MOD=998244353;
int n,opt[510],a[510],f[510],pw[510];
char s[10];
void update(int&x,int y){(x+=y)%=MOD;}
int main()
{
	scanf("%d",&n);
	int ans=0;
	pw[0]=1;
	rep(i,n)pw[i]=pw[i-1],update(pw[i],pw[i-1]);
	rep(i,n)
	{
		scanf("%s",s);
		if(s[0]=='-')opt[i]=0;
		else
		{
			opt[i]=1;
			scanf("%d",&a[i]);
			update(ans,a[i]);
		}
	}
	ans=1ll*ans*pw[n-1]%MOD;
	rep(i,n)
	if(opt[i])
	{
		f[0]=1;rep(j,n)f[j]=0;
		rep(j,n)if(j!=i)
		{
			if(!opt[j]&&j>i)update(ans,MOD-1ll*a[i]*f[0]%MOD*pw[n-j]%MOD);
			if(!opt[j]){if(j<i)update(f[0],f[0]);rep(k,n)update(f[k-1],f[k]);}
			else if(a[j]>a[i]||(a[j]==a[i]&&j>i))rep(k,n+1)update(f[k-1],f[k-1]);
			else for(int k=n;k;k--)update(f[k],f[k-1]);
		}
	}
	printf("%d\n",ans);
    return 0;
}