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
typedef unsigned long long ULL;
typedef long double LD;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n,a[100010];
        scanf("%d",&n);
        LL ans1=0;
        rep(i,n)scanf("%d",&a[i]),ans1+=max(a[i]-a[i-1],0);
        sort(a+1,a+n+1);
        puts(ans1==a[n]?"YES":"NO");
    }
    return 0;
}