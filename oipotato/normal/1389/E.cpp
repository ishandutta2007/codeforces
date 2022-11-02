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
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int m,d,w;
		scanf("%d%d%d",&m,&d,&w);m=min(m,d);
		if(m<2){puts("0");continue;}
		d--;w/=gcd(w,d);
		int cnt=(m-1)/w;
		long long sum=1ll*cnt*(cnt+1)/2*w;
		printf("%lld\n",1ll*m*cnt-sum);
	}
	return 0;
}