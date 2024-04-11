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
	int a[10];
	rep(i,4)scanf("%d",&a[i]);
	sort(a+1,a+5);
	printf("%d %d %d\n",a[4]-a[1],a[4]-a[2],a[4]-a[3]);
    return 0;
}