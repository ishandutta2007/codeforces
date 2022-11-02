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
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,a,b,c,d;scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
		int l=n*(a-b),r=n*(a+b);
		if(r<c-d||l>c+d)puts("No");else puts("Yes");
	}
    return 0;
}