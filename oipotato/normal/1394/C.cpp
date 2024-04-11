#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int x[300010],y[300010],n;
char s[500010];
pair<int,int> solve(int lx,int rx,int ly,int ry,int U,int D)
{
	if(lx>rx||ly>ry||D>U)return mp(0,0);
	if(D<=lx-ly&&lx-ly<=U&&lx+ly)return mp(lx,ly);
	if(D<=lx-ry&&lx-ry<=U&&lx+ry)return mp(lx,ry);
	if(D<=rx-ly&&rx-ly<=U&&rx+ly)return mp(rx,ly);
	if(D<=rx-ry&&rx-ry<=U&&rx+ry)return mp(rx,ry);

	if(ly<=lx-U&&lx-U<=ry&&2*lx-U)return mp(lx,lx-U);
	if(ly<=rx-U&&rx-U<=ry&&2*rx-U)return mp(rx,rx-U);
	if(lx<=ly+U&&ly+U<=rx&&2*ly+U)return mp(ly+U,ly);
	if(lx<=ry+U&&ry+U<=rx&&2*ry+U)return mp(ry+U,ry);

	U=D;
	if(ly<=lx-U&&lx-U<=ry&&2*lx-U)return mp(lx,lx-U);
	if(ly<=rx-U&&rx-U<=ry&&2*rx-U)return mp(rx,rx-U);
	if(lx<=ly+U&&ly+U<=rx&&2*ly+U)return mp(ly+U,ly);
	if(lx<=ry+U&&ry+U<=rx&&2*ry+U)return mp(ry+U,ry);

	return mp(0,0);
}
bool check(int d,bool print)
{
	int lx=0,rx=(int)1e6,ly=0,ry=(int)1e6,U=(int)1e6,D=-(int)1e6;
	rep(i,n)lx=max(lx,x[i]-d),rx=min(rx,x[i]+d),ly=max(ly,y[i]-d),ry=min(ry,y[i]+d),U=min(U,x[i]-y[i]+d),D=max(D,x[i]-y[i]-d);
	// printf("%d %d %d %d %d %d\n",lx,rx,ly,ry,U,D);
	auto p=solve(lx,rx,ly,ry,U,D);
	// printf("%d %d\n",p.first,p.second);
	if(print)
	{
		printf("%d\n",d);
		rep(i,p.first)putchar('B');
		rep(i,p.second)putchar('N');
		puts("");
	}
	return p.first+p.second>0;
}
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		rep(j,len)if(s[j]=='B')x[i]++;else y[i]++;
	}
	// check(500,0);return 0;
	int l=-1,r=(int)5e5+1;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(check(mid,0))r=mid;else l=mid;
	}
	check(r,1);
	return 0;
}