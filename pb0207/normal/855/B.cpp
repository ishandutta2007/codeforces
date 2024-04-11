#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

const ll INF=1e18;

ll n,p,q,r;

ll a[N],mnf[N],mxf[N],mnb[N],mxb[N],ap=-INF,aq=-INF,ar=-INF,ans=-4*INF;

int main()
{
	cin>>n>>p>>q>>r;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=n+1;i++)
		mnb[i]=INF,mxf[i]=-INF,mnf[i]=INF,mxb[i]=-INF;
	for(int i=1;i<=n;i++)
		mnf[i]=min(mnf[i-1],a[i]),mxf[i]=max(mxf[i-1],a[i]);
	for(int i=n;i>=1;i--)
		mnb[i]=min(mnb[i+1],a[i]),mxb[i]=max(mxb[i+1],a[i]);
	for(int i=1;i<=n;i++)
	{
	    ap=-INF;
	    aq=-INF;
	    ar=-INF;
		ap=max(ap,p*mxf[i]),ap=max(ap,p*mnf[i]);
		aq=max(aq,q*a[i]);
		ar=max(ar,r*mnb[i]),ar=max(ar,r*mxb[i]);
		ans=max(ans,ap+aq+ar);
	}
	cout<<ans;
}