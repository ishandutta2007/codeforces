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
int c[1010],n;
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		int x;scanf("%d",&x);
		c[x]++;
	}
	int ans1=0,ans2=0;
	rep(i,1000)
	{
		if(c[i])ans2++;
		ans1=max(ans1,c[i]);
	}
	printf("%d %d\n",ans1,ans2);
    return 0;
}