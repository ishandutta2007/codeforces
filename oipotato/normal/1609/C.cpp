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
const int N=1000010;
int a[N],b[N],prime[N],n,e,tot;
bool notp[N];
LL work(int n)
{
	LL res=0;
	rep(i,n)if(b[i]>1&&!notp[b[i]])
	{
		int l=i,r=i;
		for(;l>1&&b[l-1]==1;l--);
		for(;r<n&&b[r+1]==1;r++);
		res+=(LL)(i-l+1)*(r-i+1)-1;
	}
	return res;
}
int main()
{
	int T;
	for(int i=2;i<=1000000;i++)
	{
		if(!notp[i])prime[++tot]=i;
		for(int j=1;j<=tot&&(LL)i*prime[j]<=1000000;j++)
		{
			notp[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&e);
		rep(i,n)scanf("%d",&a[i]);
		LL ans=0;
		rep(i,e)
		{
			int cnt=0;
			for(int j=i;j<=n;j+=e)b[++cnt]=a[j];
			ans+=work(cnt);
		}
		printf("%lld\n",ans);
	}
    return 0;
}