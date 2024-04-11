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
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	int ans=a*n;
	rep(i,n)
	{
		int x=max(0,n-m*i);
		ans=min(ans,i*b+x*a);
	}
	printf("%d\n",ans);
    return 0;
}