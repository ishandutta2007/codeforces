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
int a[110];
int main()
{
	int cnt=0;
	rep(i,9)
	{
		int x=0;
		rep(j,9)x=x*10+i,a[++cnt]=x;
	}
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		scanf("%d",&n);
		int ans=0;rep(i,cnt)if(a[i]<=n)ans++;
		printf("%d\n",ans);
	}
    return 0;
}