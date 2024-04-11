#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
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
int a[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,d;scanf("%d%d",&n,&d);
		rep(i,n)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		puts(a[1]+a[2]<=d||a[n]<=d?"YES":"NO");
	}
    return 0;
}