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
int f[20];
vector<pair<int,int>>ans;
int ask(int d)
{
	ans.clear();
	rep(i,200)if(i%d==0)rep(j,200)ans.pb(mp(i,j));
	int cnt=ans.size();
	printf("? %d\n",cnt);
	rep(i,cnt)printf("%d %d%c",ans[i-1].first,ans[i-1].second," \n"[i==cnt]);
	fflush(stdout);
	int tmp;scanf("%d",&tmp);
	return tmp;
}
int main()
{
	f[0]=ask(1);
	int l=0,r=8;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		f[mid]=ask(1<<mid);
		if(f[mid]*(1<<mid)!=f[0])r=mid;else l=mid;
	}
	int h=abs(2*f[l+1]-f[0]/(1<<l))-1,b=f[0]/(h+1)-1;
	printf("! %d\n",2*(h+b));
    return 0;
}