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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,a[50010],b[50010];scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)scanf("%d",&b[i]);
		int delta=(int)1e9;
		rep(i,n)if(a[i]&&b[i]){delta=a[i]-b[i];break;}
		bool flag=delta>=0;
		rep(i,n)if(b[i]){if(a[i]-delta!=b[i])flag=0;}else{if(a[i]-delta>0)flag=0;}
		puts(flag?"YES":"NO");
	}
    return 0;
}