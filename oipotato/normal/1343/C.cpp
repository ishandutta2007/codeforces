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
int n,a[200010];
int sig(int x){return x/abs(x);}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		LL sum=0;
		for(int i=1;i<=n;)
		{
			int j=i;
			for(;j<=n&&sig(a[j])==sig(a[i]);j++);
			int mx=a[i];
			for(int k=i;k<j;k++)mx=max(mx,a[k]);
			sum+=mx;i=j;
		}
		printf("%lld\n",sum);
	}
    return 0;
}