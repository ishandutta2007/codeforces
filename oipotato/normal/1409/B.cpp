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
		int a,b,x,y,n;
		scanf("%d%d%d%d%d",&a,&b,&x,&y,&n);
		printf("%lld\n",min(cal(a,b,x,y,n),cal(b,a,y,x,n)));
	}
	return 0;
}