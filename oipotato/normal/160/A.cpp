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
int n,a[110];
int main()
{
	scanf("%d",&n);
	int sum=0;
	rep(i,n)scanf("%d",&a[i]),sum+=a[i];
	sort(a+1,a+n+1,greater<int>());
	int now=0;
	rep(i,n)
	{
		now+=a[i];
		if(now>sum-now){printf("%d\n",i);return 0;}
	}
    return 0;
}