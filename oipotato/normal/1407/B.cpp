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
int a[1010];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		sort(a+1,a+n+1,greater<int>());
		int now=a[1];
		for(int i=2;i<=n;i++)
		{
			int tmp=i;
			for(int j=i+1;j<=n;j++)if(gcd(a[j],now)>gcd(a[tmp],now))tmp=j;
			swap(a[tmp],a[i]);
			now=gcd(now,a[i]);
		}
		rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}