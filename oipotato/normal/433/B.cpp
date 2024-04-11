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
LL s[2][100010];
int a[100010],n,m;
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]),s[0][i]=s[0][i-1]+a[i];
	sort(a+1,a+n+1);
	rep(i,n)s[1][i]=s[1][i-1]+a[i];
	scanf("%d",&m);
	rep(i,m)
	{
		int opt,l,r;scanf("%d%d%d",&opt,&l,&r);
		printf("%lld\n",s[opt-1][r]-s[opt-1][l-1]);
	}
    return 0;
}