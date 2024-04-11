#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
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
	int k,a[20];a[0]=0;
	scanf("%d",&k);
	rep(i,12)scanf("%d",&a[i]);
	sort(a+1,a+13,greater<int>());
	rep(i,12)a[i]+=a[i-1];
	if(a[12]<k)puts("-1");
	else printf("%d\n",lower_bound(a,a+13,k)-a);
    return 0;
}