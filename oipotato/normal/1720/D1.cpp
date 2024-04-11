#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=10000010;
int go[N][2],ans[N][2][2],f[N],a[N],n,tot;
void insert(int x,int a,int f)
{
	int p=0;
	for(int i=30;i>=0;i--)
	{
		int l=(x>>i)&1,r=(a>>i)&1,b=l^r;
		ans[p][l][r]=max(ans[p][l][r],f);
		if(!go[p][b])
		{
			go[p][b]=++tot;
			memset(go[tot],0,sizeof(go[tot]));
			memset(ans[tot],0,sizeof(ans[tot]));
		}
		p=go[p][b];
	}
}
int get(int a,int x)
{
	int res=0,p=0;
	for(int i=30;i>=0;i--)
	{
		int l=(a>>i)&1,r=(x>>i)&1,b=l^r;
		for(int j=0;j<2;j++)for(int k=0;k<2;k++)if((l^j)>(r^k))res=max(res,ans[p][j][k]);
		if(!go[p][b])return res;
		p=go[p][b];
	}
	return res;
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		tot=0;memset(go[0],0,sizeof(go[0]));
		memset(ans[0],0,sizeof(ans[0]));
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			f[i]=get(a[i],i)+1;
			insert(i,a[i],f[i]);
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
    return 0;
}