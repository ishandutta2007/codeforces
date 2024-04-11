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
int n,ans,a[110],b[101];
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&a[i],&b[i]);
	rep(i,n)rep(j,n)
	{
		if(i==j)continue;
		if(a[i]==b[j])ans++;
	}
	printf("%d\n",ans);
    return 0;
}