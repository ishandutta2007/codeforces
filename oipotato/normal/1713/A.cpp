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
        int n;
        scanf("%d",&n);
        int xl=0,xr=0,yl=0,yr=0;
        rep(i,n)
        {
            int x,y;scanf("%d%d",&x,&y);
            xl=min(xl,x);xr=max(xr,x);
            yl=min(yl,y);yr=max(yr,y);
        }
        printf("%d\n",(abs(xl)+xr+abs(yl)+yr)*2);
    }
    return 0;
}