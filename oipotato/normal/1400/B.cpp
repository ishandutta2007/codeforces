#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int ans[110],a[110],n;
char s[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int p,f,cnts,cntw,s,w;
		scanf("%d%d%d%d%d%d",&p,&f,&cnts,&cntw,&s,&w);
		if(s>w)swap(s,w),swap(cnts,cntw);
		int ans=0;
		for(int i=0;i<=cnts;i++)
		{
			if(1ll*i*s>p)break;
			int tans=i+min(cntw,(p-i*s)/w);
			int rs=cnts-i,rw=max(0,cntw-(p-i*s)/w);
			int tmp=min(rs,f/s);
			tans+=tmp+min(rw,(f-tmp*s)/w);
			ans=max(ans,tans);
		}
		printf("%d\n",ans);
	}
    return 0;
}