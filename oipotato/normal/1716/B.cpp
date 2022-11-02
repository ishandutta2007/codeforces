#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",n);
		int a[110];
		rep(i,n)a[i]=i;
		rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
		rep(i,n-1)
		{
			swap(a[i],a[n]);
			rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
		}
	}
    return 0;
}