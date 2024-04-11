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
LL cal(int x){return (LL)x*(x-1)/2;}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int x=n/m,y=n%m;
	printf("%lld %lld\n",cal(x)*(m-y)+cal(x+1)*y,cal(n-m+1));
    return 0;
}