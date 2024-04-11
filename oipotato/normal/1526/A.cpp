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
		int n,a[55];
		scanf("%d",&n);rep(i,2*n)scanf("%d",&a[i]);
		sort(a+1,a+2*n+1);
		rep(i,2*n)printf("%d%c",(i&1)?a[i/2+1]:a[i/2+n]," \n"[i==2*n]);
	}
    return 0;
}