#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;

struct P
{
	int x,y;
	void in() {scanf("%d%d",&x,&y);}
	long long operator ^(P b) {return 1ll*x*b.y-1ll*y*b.x;}
}a[500010];

int n,ans,r,nw,nwx,nwy;
long long S,nwS;

int main()
{
	scanf("%d",&n),ans=0,S=0;
	for (int i=1; i<=n; i++) a[i].in();
	reverse(a+1,a+1+n);
	for (int i=1; i<=n; i++) S+=(a[i]^a[i+1]);
	S+=(a[n]^a[1]),ans=1ll*n*(n-3)/2%mod*(S%mod)%mod,r=2,nwx=nwy=0,nwS=0,nw=0;
	for (int i=1,nxt,nxtr; i<=n; i++)
	{
		nxt=(i==n?1:i+1),nxtr=(r==n?1:r+1);
		if (i!=1&&r!=i) 
		{
			nwS=nwS-(a[r]^a[i-1])-(a[i-1]^a[i])+(a[r]^a[i]);
			nw=(nw-(1ll*nwx*a[i-1].y-1ll*nwy*a[i-1].x)-(a[i-1]^a[i])%mod*(r<i-1?r-i+n:r-i))%mod;
			nw=(nw+1ll*nwx*a[i].y-1ll*nwy*a[i].x)%mod;
			nwx=(nwx-a[nxt].x)%mod,nwy=(nwy-a[nxt].y)%mod;
		}
		while (nwS-(a[r]^a[i])+(a[r]^a[nxtr])+(a[nxtr]^a[i])<=S/2)
		{
			if (nxtr!=nxt)
			{
				nwx=(nwx+a[nxtr].x)%mod,nwy=(nwy+a[nxtr].y)%mod;
				nwS=nwS-(a[r]^a[i])+(a[r]^a[nxtr])+(a[nxtr]^a[i]);
				nw=(nw+nwS)%mod;
			}
			r=nxtr,nxtr=(r==n?1:r+1);
		}
		if (nwS*2==S) ans=(ans+nwS)%mod;
		ans=(ans-2ll*nw)%mod;
	}
	return printf("%d\n",(ans+mod)%mod),0;
}