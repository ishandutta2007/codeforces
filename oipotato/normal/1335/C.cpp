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
int c[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		rep(i,n)c[i]=0;
		rep(i,n){int x;scanf("%d",&x);c[x]++;}
		int num=0,mx=0;
		rep(i,n){if(c[i])num++;mx=max(mx,c[i]);}
		if(mx-1>=num)printf("%d\n",num);
		else if(num-1>=mx)printf("%d\n",mx);
		else printf("%d\n",mx-1);
	}
    return 0;
}