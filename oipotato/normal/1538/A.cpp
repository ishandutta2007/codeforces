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
int a[110];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		int mn=1,mx=1;
		rep(i,n)
		{
			if(a[i]>a[mx])mx=i;
			if(a[i]<a[mn])mn=i;
		}
		if(mn>mx)swap(mn,mx);
		printf("%d\n",min(min(mx,n-mn+1),mn+n-mx+1));
	}
    return 0;
}