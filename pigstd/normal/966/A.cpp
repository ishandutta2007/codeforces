#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=1e5+10;
int n,m,c1,c2,v;
int a1[M],a2[M];

signed main()
{
	cin>>n>>m>>c1>>c2>>v;
	for (int i=1;i<=c1;i++)cin>>a1[i];
	for (int i=1;i<=c2;i++)cin>>a2[i];
	sort(a1+1,a1+c1+1);sort(a2+1,a2+c2+1);
	WT
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		if (y1>y2)swap(y1,y2);
		int d=abs(x1-x2),ans=inf,x=inf;
		if (x1==x2){cout<<abs(y1-y2)<<endl;continue;}
		//
		int tl=1,tr=c1,p=c1+1;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (a1[Mid]>=y1)p=Mid,tr=Mid-1;
			else tl=Mid+1;
		}
		if (p!=c1+1)
			if (a1[p]<=y2)x=y2-y1;
		if (p!=1)
			x=min(x,abs(y1-a1[p-1])+abs(y2-a1[p-1]));
		tl=1,tr=c1,p=0;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (a1[Mid]<=y2)p=Mid,tl=Mid+1;
			else tr=Mid-1;
		}
		if (p!=c1)x=min(x,abs(y1-a1[p+1])+abs(y2-a1[p+1]));
		ans=min(ans,x+d);x=inf;
		//
		tl=1,tr=c2,p=c2+1;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (a2[Mid]>=y1)p=Mid,tr=Mid-1;
			else tl=Mid+1;
		}
		if (p!=c2+1)
			if (a2[p]<=y2)x=y2-y1;
		if (p!=1)
			x=min(x,abs(y1-a2[p-1])+abs(y2-a2[p-1]));
		tl=1,tr=c2,p=0;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (a2[Mid]<=y2)p=Mid,tl=Mid+1;
			else tr=Mid-1;
		}
		if (p!=c2)x=min(x,abs(y1-a2[p+1])+abs(y2-a2[p+1]));
		ans=min(ans,x+(d-1)/v+1);cout<<ans<<endl;
	}
	return 0;
}