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
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int ma1=0,ma2=0;
	rep(i,n){int x;scanf("%d",&x);if(x>ma1)ma2=ma1,ma1=x;else if(x>ma2)ma2=x;}
	long long p=1ll*k*ma1+ma2;
	printf("%lld\n",p*(m/(k+1))+1ll*ma1*(m%(k+1)));
	return 0;
}