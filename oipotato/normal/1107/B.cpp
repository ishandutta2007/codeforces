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
int cnt[10];
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		long long k;int x;
		scanf("%lld%d",&k,&x);
		printf("%lld\n",9*(k-1)+x);
	}
	return 0;
}