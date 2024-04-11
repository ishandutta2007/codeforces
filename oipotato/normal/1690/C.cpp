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
		int n,s[200010],f[200010];scanf("%d",&n);
		rep(i,n)scanf("%d",&s[i]);
		rep(i,n)scanf("%d",&f[i]);
		rep(i,n)printf("%d%c",f[i]-max(f[i-1],s[i])," \n"[i==n]);
	}
    return 0;
}