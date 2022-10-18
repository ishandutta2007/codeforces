#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned
int dp[35][1010][4];
int mod=7340033;
int r1(int d, int k, int w)
{
    if (k==0)
        return 1;
    if (d==0)
        return 0;
    if (w==4)
    {
        if (k==1)
            return 1;
        return 0;
    }
    if (dp[d][k][w]!=-1)
        return dp[d][k][w];
    int res=0;
    FOR(i,0,k)
    {
        LL c=r1(d-1,i,0);
        c*=r1(d,k-i,w+1);
        c%=mod;
        res+=c;
        if (res>=mod)
            res-=mod;
    }
    return dp[d][k][w]=res;
}
int main()
{
#ifdef Fcdkbear
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    double beg=clock();
#endif
    MEMS(dp,-1);
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int v,k;
        scanf("%d%d",&v,&k);
        if ((v&1)==0)
        {
            if (k==0)
                printf("1\n");
            else
                printf("0\n");
        }
        else
        {
            int d=0;
            while ((v & 1) && v > 1)
            {
              v /= 2;
              d++;
            }
            int res=r1(d,k,0);
            printf("%d\n",res);
        }
    }
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}