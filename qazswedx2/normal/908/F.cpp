#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1000005];
char s[1000005];
inline int getlen(int x,int y)
{
	if(!x||!y) return 0;
	return a[y]-a[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %c",&a[i],&s[i]);
	int fb=0,lb=0,fr=0,lr=0,lg=0,mxb=0,mxr=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='B')
		{
			if(!fb) fb=i,mxb=max(mxb,getlen(lg,i));
			else mxb=max(mxb,getlen(lb,i));
			lb=i;
		}
		if(s[i]=='R')
		{
			if(!fr) fr=i,mxr=max(mxr,getlen(lg,i));
			else mxr=max(mxr,getlen(lr,i));
			lr=i;
		}
		if(s[i]=='G')
		{
			if(!lg)
				ans+=getlen(fb,i)+getlen(fr,i);
			else
			{
				ll v=getlen(lg,i);
				mxb=max(mxb,getlen(lb,i));
				mxr=max(mxr,getlen(lr,i));
				if(!lb) mxb=v;
				if(!lr) mxr=v;
				ans+=min(2*v,3*v-mxb-mxr);
			//	printf("ans=%lld,getlen=%d,%d,%d,%d,%d\n",ans,getlen(lg,i),getlen(fb,i),getlen(lg,lb),getlen(fr,i),getlen(lg,lr));
			}
			lg=i;
			fb=lb=fr=lr=mxb=mxr=0;
		}
	}
	ans+=getlen(lg,lb)+getlen(lg,lr);
	if(!lg) ans+=getlen(fb,lb)+getlen(fr,lr);
	printf("%lld\n",ans);
	return 0;
}