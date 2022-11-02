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
	int n;
	scanf("%d",&n);
	int mn=10001,mx=0;
	int ans=0;
	rep(i,n)
	{
		int x;scanf("%d",&x);
		if(i>1&&(x<mn||x>mx))ans++;
		mx=max(mx,x);mn=min(mn,x);
	}
	printf("%d\n",ans);
    return 0;
}