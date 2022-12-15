#include<bits/stdc++.h>
using namespace std;

int n,po;
long long nw,a[100011],ans,r,len,NW,le,g[100011],la,sum;
char s[100011];

long long getmax(long long a,long long b) {return a>b?a:b;}

int main()
{
	scanf("%d",&n);  le=sum=0; g[n+1]=0;
	for (int i=1; i<=n; i++) scanf("%I64d",&a[i]);
	scanf("%s",s+1); nw=1; po=n+1;
	for (int i=1; i<=n; i++) if (s[i]=='W') {po=i; break;}
	for (int i=1; i<po; i++) le+=a[i];
	for (int i=po; i<=n; i++) sum+=a[i];
	NW=0;
	for (int i=n; i; i--)
		if (s[i]!='L') g[i]=NW=getmax(NW-a[i],0);
		else NW+=a[i]; 
	NW=0;
	if (s[1]=='W') le=sum;
	while (nw<=n)
	{
		if (s[nw]=='G')
		{
			if (NW>=le+g[po]) ans+=le,nw=po,NW-=le,le=sum; else
			if (NW+a[nw]>=le-a[nw]+g[po]) ans+=3*(le-NW)+NW+2*g[po],nw=po,NW=g[po],le=sum;
			else 
			{
				r=nw; len=0;
				while (r<n&&s[r+1]=='L') r++,len+=a[r];
				if (NW+a[nw]>=len) ans+=5*a[nw]+len,NW+=a[nw]-len;
				else ans+=len+(len-NW)*5,NW=0;
				le-=(a[nw]+len); nw=r+1;
				if (nw==n+1) break;
				if (s[nw]=='W') le=sum;
			}
		} else
		{
			if (NW>=le) ans+=le,nw=n+1; else
			if (NW+a[nw]>=le-a[nw]) ans+=2*(le-NW)+NW,nw=n+1;
			else
			{
				r=nw; len=0;
				while (r<n&&s[r+1]=='L') r++,len+=a[r];
				if (g[r+1]+len>=a[nw]+NW) ans+=3*(g[r+1]+len-NW)+len,NW=g[r+1];
				else ans+=a[nw]*3+len,NW+=a[nw]-len;
				le-=(a[nw]+len); nw=r+1;
				if (nw==n+1) break;
				if (s[nw]=='G')
				{
					po=n+1; sum=le; le=0;
					for (int j=nw+1; j<=n; j++) if (s[j]=='W') {po=j; break;}
					for (int j=nw; j<po; j++) le+=a[j],sum-=a[j];
				}
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}