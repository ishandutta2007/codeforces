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
int a[10],ans[10];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;scanf("%d",&n);
		int cnt=0;
		for(;n;n/=10)a[++cnt]=n%10;
		int now=1;
		int tot=0;
		rep(i,cnt)
		{
			if(a[i])ans[++tot]=a[i]*now;
			now*=10;
		}
		printf("%d\n",tot);
		rep(i,tot)printf("%d%c",ans[i]," \n"[i==tot]);
	}
    return 0;
}