#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
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
const int N=500010;
const int P=1000000013;
pair<int,long long>h[N];
int p[N],n,m;
LL gcd(LL a,LL b){return !b?a:gcd(b,a%b);}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&m);
		rep(i,n)scanf("%lld",&h[i].second),h[i].first=1,p[i]=(i+19260817)%P;
		rep(i,m)
		{
			int x,y;scanf("%d%d",&x,&y);
			h[y].first=(LL)h[y].first*p[x]%P;
		}
		sort(h+1,h+n+1);
		LL ans=0;
		rep(i,n)
		{
			int j=i;
			for(;j<=n&&h[j].first==h[i].first;j++);
			if(h[i].first!=1)
			{
				LL tmp=0;
				for(int k=i;k<j;k++)tmp+=h[k].second;
				ans=gcd(ans,tmp);
			}
			i=j-1;
		}
		printf("%lld\n",ans);
	}
    return 0;
}