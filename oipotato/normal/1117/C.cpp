#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int n,x1,y1,x2,y2,dx,dy,sx[100010],sy[100010];
char s[100010];
bool check(long long stp)
{
	long long x=x1+sx[n]*(stp/n)+sx[stp%n],y=y1+sy[n]*(stp/n)+sy[stp%n];
	return abs(x-x2)+abs(y-y2)<=stp;
}
int main()
{
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	dx=x2-x1;dy=y2-y1;
	scanf("%d",&n);
	scanf("%s",s+1);
	if(x1==x2&&y1==y2){puts("0");return 0;}
	rep(i,n)
	{
		sx[i]=sx[i-1];sy[i]=sy[i-1];
		if(s[i]=='U')sy[i]++;
		else if(s[i]=='D')sy[i]--;
		else if(s[i]=='L')sx[i]--;
		else sx[i]++;
		if(abs(x2-(x1+sx[i]))+abs(y2-(y1+sy[i]))<=i){printf("%d\n",i);return 0;}
	}
	//if(abs(x2-(x1+sx[n]))+abs(y2-(y1+sy[n]))-n>=abs(dx)+abs(dy)){puts("-1");return 0;}
	long long l=0,r=1000000ll*1000000000+100;
	for(;l<r-1;)
	{
		long long mid=(l+r)>>1;
		if(check(mid))r=mid;else l=mid;
	}
	printf("%lld\n",r==1000000ll*1000000000+100?-1:r);
	return 0;
}