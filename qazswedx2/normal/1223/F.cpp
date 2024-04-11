#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int mod[55]={920398243,920398253,920398313,920398319,920398327,920398333,920398351,920398379,
920398387,920398393,920398397,920398417,920398459,920398471,920398481,920398487,
920398499,920398517,920398519,920398529,920398543,920398601,920398637,920398639,
920398657,920398663,920398679,920398691,920398693,920398729,920398747,920398757,
920398811,920398813,920398837,920398891,920398909,920398951,920399093,920399101,
920399131,920399141,920399143,920399149,920399153,920399191,920399231,920399237,
920399243,920399251};
int fpow(int x,int y,int mod)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int m1,m2,bs1,bs2,ibs1,ibs2;
struct pt
{
	int v1,v2;
	pt(int v1=0,int v2=0):v1(v1),v2(v2){}
	void ins(int x)
	{
		v1=(1ll*v1*bs1%mod[m1]+x)%mod[m1];
		v2=(1ll*v2*bs2%mod[m2]+x)%mod[m2];
	}
	void del(int x)
	{
		v1=1ll*(v1-x+mod[m1])*ibs1%mod[m1];
		v2=1ll*(v2-x+mod[m2])*ibs2%mod[m2];
	}
	bool operator<(const pt x) const
	{
		if(v1!=x.v1) return v1<x.v1;
		return v2<x.v2;
	}
	bool operator==(const pt x) const
	{
		return v1==x.v1&&v2==x.v2;
	}
}p[500005];
int t,n,a[500005],tp;
int st[500005];
int main()
{
	//freopen("CF1223F.in","r",stdin);
	srand(time(0));
	scanf("%d",&t);
	while(t--)
	{
		m1=rand()%50,m2=rand()%50;
		while(m1==m2) m1=rand()%50,m2=rand()%50;
		bs1=3294842+rand()%100000;
		bs2=3294842+rand()%100000;
		ibs1=fpow(bs1,mod[m1]-2,mod[m1]);
		ibs2=fpow(bs2,mod[m2]-2,mod[m2]);
		p[0]=pt(0,0);
		tp=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			p[i]=p[i-1];
			if(tp&&st[tp]==x) p[i].del(x),tp--;
			else p[i].ins(x),st[++tp]=x;
		}
		sort(p,p+n+1);
		ll ans=0;
		for(int l=0,r;l<=n;l=r+1)
		{
			r=l;
			while(r<n&&p[r+1]==p[l]) r++;
			ans+=1ll*(r-l+1)*(r-l)/2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}