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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int w,h,n;
		scanf("%d%d%d",&w,&h,&n);
		LL ans=1;
		for(;w%2==0&&ans<n;ans*=2,w/=2);
		w=h;
		for(;w%2==0&&ans<n;ans*=2,w/=2);
		puts(ans>=n?"YES":"NO");
	}
    return 0;
}