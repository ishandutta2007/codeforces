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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int c[110],n;
		scanf("%d",&n);for(int i=0;i<=100;i++)c[i]=0;
		rep(i,n){int x;scanf("%d",&x);c[x]++;}
		for(int i=0;i<=100;i++)if(c[i])printf("%d ",i),c[i]--;
		for(int i=0;i<=100;i++)for(;c[i]--;printf("%d ",i));
		puts("");
	}
    return 0;
}