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
int a[200010],n;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		LL sum=0;
		rep(i,n)scanf("%d",&a[i]),sum+=a[i];
		if(sum%n!=0){puts("-1");continue;}
		sort(a+1,a+n+1);sum/=n;
		printf("%d\n",n-(upper_bound(a+1,a+n+1,sum)-a)+1);
	}
    return 0;
}