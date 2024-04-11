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
bool v[100010];
int main()
{
	int a[10];
	rep(i,5)scanf("%d",&a[i]);
	int ans=0;
	rep(i,4)
	{
		for(int j=a[i];j<=a[5];j+=a[i])v[j]=1;
	}
	rep(i,a[5])ans+=v[i];
	printf("%d\n",ans);
    return 0;
}