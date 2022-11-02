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
int n,a[5010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);rep(i,n)scanf("%d",&a[i]);
		bool flag=0;
		rep(i,n)rep(j,i-2)if(a[i]==a[j])flag=1;
		puts(flag?"YES":"NO");
	}
    return 0;
}