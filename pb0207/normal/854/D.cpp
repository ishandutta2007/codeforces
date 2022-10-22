#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7;


typedef long long ll;
const ll INF=1e16;

struct node{
	ll d,f,t,c;
}a[N],b[N];

ll n,m,k,x,y,to[N],bc[N],nowa,nowb,ans1[N*13+N],ans2[N*13+N],ans=INF,flag1,flag2,via[N],vib[N],ta,tb;

bool cmp(node a,node b)
{
	return a.d<b.d;
}

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		ll dd,ff,tt,cc;
		scanf("%I64d%I64d%I64d%I64d",&dd,&ff,&tt,&cc);

		if(tt==0)
			a[++x].d=dd,a[x].f=ff,a[x].t=tt,a[x].c=cc;
		else
			b[++y].d=dd,b[y].f=ff,b[y].t=tt,b[y].c=cc;
	}
	sort(a+1,a+x+1,cmp);
	sort(b+1,b+y+1,cmp);
	nowa=1,nowb=y;
	for(int i=1;i<=n;i++)
		to[i]=bc[i]=INF;
	for(ll i=0;i<=(ll)(1e6)+(ll)(2e5)+1;i++)
		ans1[i]=ans2[i]=INF;
	for(ll i=1;i<=(ll)(1e6)+(ll)(2e5);i++)
	{
		ans1[i]=ans1[i-1];
		while(a[nowa].d<=i&&nowa<=x)
		{
			if(to[a[nowa].f]>a[nowa].c)
			{
				if(flag1)
					ans1[i]-=to[a[nowa].f]-a[nowa].c;
				to[a[nowa].f]=a[nowa].c;
			}
			if(!via[a[nowa].f])
				via[a[nowa].f]=true,ta++;
			if(!flag1&&ta==n)
			{
				ans1[i]=0;
				for(int j=1;j<=n;j++)
					ans1[i]+=to[j],flag1=true;
			}
			nowa++;
		}
	}
	for(ll i=(ll)(1e6)+(ll)(2e5);i>=1;i--)
	{
		ans2[i]=ans2[i+1];
		while(b[nowb].d>=i+k&&nowb>=1)
		{
			if(bc[b[nowb].t]>b[nowb].c)
			{
				if(flag2)
					ans2[i]-=bc[b[nowb].t]-b[nowb].c;
				bc[b[nowb].t]=b[nowb].c;
			}
			if(!vib[b[nowb].t])
				vib[b[nowb].t]=true,tb++;
			if(!flag2&&tb==n)
			{
				ans2[i]=0;
				for(int j=1;j<=n;j++)
					ans2[i]+=bc[j],flag2=true;
			}	
			nowb--;
		}
	} 
	for(int i=1;i<=(int)(1e6);i++)
	if(ans1[i]!=INF&&ans2[i]!=INF)
		ans=min(ans,ans1[i]+ans2[i+1]);
	cout<<(ans==INF?-1:ans);
}