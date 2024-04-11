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
int c[1010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		rep(i,1000)c[i]=0;
		rep(i,n){int x;scanf("%d",&x);c[x]++;}
		int pos=-1;
		rep(i,m){int x;scanf("%d",&x);if(c[x])pos=x;}
		if(pos!=-1)printf("YES\n1 %d\n",pos);
		else puts("NO");
	}
    return 0;
}