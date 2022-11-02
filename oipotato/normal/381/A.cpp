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
int a[1010],n;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	int l=1,r=n;
	int ans[2]={0,0};
	rep(i,n)
	{
		if(a[l]>a[r])ans[i&1]+=a[l++];else ans[i&1]+=a[r--];
	}
	printf("%d %d\n",ans[1],ans[0]);
    return 0;
}