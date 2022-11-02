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
		int n,m;scanf("%d%d",&n,&m);
		bool flag=0;
		rep(i,n)
		{
			int a[3][3];
			rep(j,2)rep(k,2)scanf("%d",&a[j][k]);
			if(a[1][2]==a[2][1])flag=1;
		}
		puts(flag&&!(m&1)?"YES":"NO");
	}
    return 0;
}