#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=100111;
int n;
LL x[maxn],y[maxn],z[maxn],xx,yy,zz,la,ra,lb,rb,lc,rc,lsum,rsum;

bool check(LL v)
{
	la=x[1]+y[1]-z[1]-v;
	ra=x[1]+y[1]-z[1]+v;
	lb=x[1]-y[1]+z[1]-v;
	rb=x[1]-y[1]+z[1]+v;
	lc=-x[1]+y[1]+z[1]-v;
	rc=-x[1]+y[1]+z[1]+v;
	lsum=x[1]+y[1]+z[1]-v;
	rsum=x[1]+y[1]+z[1]+v;
	for(int i=2;i<=n;i++)
	{
		la=max(la,x[i]+y[i]-z[i]-v);
		ra=min(ra,x[i]+y[i]-z[i]+v);
		lb=max(lb,x[i]-y[i]+z[i]-v);
		rb=min(rb,x[i]-y[i]+z[i]+v);
		lc=max(lc,-x[i]+y[i]+z[i]-v);
		rc=min(rc,-x[i]+y[i]+z[i]+v);
		lsum=max(lsum,x[i]+y[i]+z[i]-v);
		rsum=min(rsum,x[i]+y[i]+z[i]+v);
	}
	LL La=la,Ra=ra,Lb=lb,Rb=rb,Lc=lc,Rc=rc,Lsum=lsum,Rsum=rsum;
	if(la%2)la++;if(ra%2)ra--;if(lb%2)lb++;if(rb%2)rb--;if(lc%2)lc++;if(rc%2)rc--;if(lsum%2)lsum++;if(rsum%2)rsum--;
	if(la<=ra&&lb<=rb&&lc<=rc&&lsum<=rsum&&la+lb+lc<=rsum&&ra+rb+rc>=lsum)return true;
	la=La;ra=Ra;lb=Lb;rb=Rb;lc=Lc;rc=Rc;lsum=Lsum;rsum=Rsum;
	if(la%2==0)la++;if(ra%2==0)ra--;if(lb%2==0)lb++;if(rb%2==0)rb--;if(lc%2==0)lc++;if(rc%2==0)rc--;if(lsum%2==0)lsum++;if(rsum%2==0)rsum--;
	if(la<=ra&&lb<=rb&&lc<=rc&&lsum<=rsum&&la+lb+lc<=rsum&&ra+rb+rc>=lsum)return true;
	return false;
}

void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",x+i,y+i,z+i);
	
	LL l=-1,r=3000000000000000001ll,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	check(r);
//	printf("la= %lld lb= %lld lc= %lld lsum= %lld\n",la,lb,lc,lsum);
//	printf("ra= %lld rb= %lld rc= %lld rsum= %lld\n",ra,rb,rc,rsum);
	if(la+lb+lc<lsum)
	{
		LL need=lsum-la-lb-lc,have_a=ra-la,have_b=rb-lb,have_c=rc-lc;
		la+=min(need,have_a);need=max(0ll,need-have_a);
		lb+=min(need,have_b);need=max(0ll,need-have_b);
		lc+=min(need,have_c);need=max(0ll,need-have_c);
	}
	printf("%lld %lld %lld\n",(la+lb)/2,(la+lc)/2,(lb+lc)/2);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
	return 0;
}