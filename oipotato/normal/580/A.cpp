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
int a[100010],n;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;)
	{
		int j=i+1;
		for(;j<=n&&a[j]>=a[j-1];j++);
		ans=max(ans,j-i);
		i=j;
	}
	printf("%d\n",ans);
    return 0;
}