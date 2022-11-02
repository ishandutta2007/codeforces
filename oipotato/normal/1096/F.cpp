#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int MOD=998244353;
int n,ans,a[200010],c[200010],s[200010];
bool vis[200010];
int mypow(int x,int n){int ans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)ans=1ll*ans*x%MOD;return ans;}
void modify(int x){for(;x<=n;x+=x&(-x))c[x]++;}
int get(int x){int s=0;for(;x;x-=x&(-x))s+=c[x];return s;}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	int cnt=0;
	for(int i=n;i;i--)
	if(a[i]!=-1)
	{
		(ans+=get(a[i]))%=MOD;
		modify(a[i]);
		vis[a[i]]=1;
	}
	else cnt++;
	ans=(ans+1ll*cnt*(cnt-1)%MOD*mypow(4,MOD-2))%MOD;
	rep(i,n)s[i]=s[i-1]+vis[i];
	int rev=mypow(cnt,MOD-2),now=0;
	rep(i,n)
	if(a[i]==-1)now++;
	else ans=(ans+1ll*(cnt-(a[i]-s[a[i]]))*now%MOD*rev)%MOD;
	now=0;
	for(int i=n;i;i--)
	if(a[i]==-1)now++;
	else ans=(ans+1ll*(a[i]-s[a[i]])*now%MOD*rev)%MOD;
	printf("%d\n",ans);
	return 0;
}