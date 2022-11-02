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
long long cal(int a,int b,int x,int y,int n)
{
	int tmp=min(a-x,n);a-=tmp;n-=tmp;
	tmp=min(b-y,n);b-=tmp;
	return 1ll*a*b;
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		int ans=(y-x)*n+x;
		for(int i=1;i<=y-x;i++)
		if((y-x)%i==0)
		{
			int tmp=n;tmp-=(y-x)/i+1;
			if(tmp<0)continue;
			int fx=x-i;
			for(;fx>0&&tmp;tmp--,fx-=i);
			fx=y;
			for(;tmp;fx+=i,tmp--);
			ans=min(ans,fx);
		}
		for(int i=1;i<=y-x;i++)
		if((y-x)%i==0)
		{
			int tmp=n;tmp-=(y-x)/i+1;
			if(tmp<0)continue;
			int fx=x-i;
			for(;fx>0&&tmp;tmp--,fx-=i);
			fx=y;
			for(;tmp;fx+=i,tmp--);
			if(fx==ans)
			{
				rep(j,n)printf("%d%c",ans-i*(n-j)," \n"[j==n]);
				break;
			}
		}
	}
	return 0;
}