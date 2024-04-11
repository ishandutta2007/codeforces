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
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		int x=n%10,cnt=0;
		for(;n;n/=10,cnt++);
		int ans=0;
		rep(i,x-1)ans+=10;
		rep(i,cnt)ans+=i;
		printf("%d\n",ans);
	}
    return 0;
}