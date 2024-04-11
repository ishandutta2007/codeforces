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
		int n,c[2],h;char s[1010];
		scanf("%d%d%d%d%s",&n,&c[0],&c[1],&h,s+1);
		int ans=0;
		rep(i,n)ans+=min(c[s[i]-'0'],c[(s[i]-'0')^1]+h);
		printf("%d\n",ans);
	}
    return 0;
}