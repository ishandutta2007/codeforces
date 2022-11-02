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
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=200010;
int s[N],a[N],n;
vector<int>g[N],ans;
pair<int,int>p[N];
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		int m,k;scanf("%d%d",&m,&k);
		a[m]+=k;g[m].pb(k);
	}
	rep(i,200000)p[i]=mp(a[i],i);
	sort(p+1,p+200001);
	reverse(p+1,p+200001);
	rep(i,200000)s[i]=s[i-1]+p[i].first;
	int x=0,y=1;
	for(int i=20;i<=200000;i++)if((LL)s[i]*y>(LL)x*i)x=s[i],y=i;
	rep(i,y)ans.pb(p[i].second);
	rep(i,19)
	{
		rep(j,200000)
		{
			int tmp=0;
			for(auto k:g[j])tmp+=min(k,i);
			p[j]=mp(tmp,j);
		}
		sort(p+1,p+200001);
		reverse(p+1,p+200001);
		int tmp=0;
		rep(j,i)tmp+=p[j].first;
		if((LL)tmp*y>x*i)
		{
			x=tmp;
			y=i;
			ans.clear();
			rep(j,i)ans.pb(p[j].second);
		}
	}
	printf("%d\n",y);
	rep(i,y)printf("%d%c",ans[i-1]," \n"[i==y]);
    return 0;
}