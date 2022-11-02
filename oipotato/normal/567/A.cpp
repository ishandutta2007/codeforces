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
int a[100010],n;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)
	{
		int y=max(a[i]-a[1],a[n]-a[i]),x=y;
		if(i>1)x=min(x,a[i]-a[i-1]);
		if(i<n)x=min(x,a[i+1]-a[i]);
		printf("%d %d\n",x,y);
	}
    return 0;
}