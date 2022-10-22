#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define LL long long
#define fi first
#define se second
#define mem(a,b) memset((a),(b),sizeof(a))
#define sqr(x) ((x)*(x))

LL N;

inline LL judge(const LL &x)
{
    return min(N-x, x*(x-1)/2)+N-x;
}

int main()
{
    int T_T;
    scanf("%d", &T_T);
    while(T_T--)
    {
        scanf("%lld", &N);
        LL l=1, r=N;
        while(r-l>2)
        {
            LL mid=(l+r)/2;
            LL midmid=(mid+r)/2;
            if(judge(midmid)>judge(mid))
                l=mid;
            else r=midmid;
        }
        printf("%lld\n", max(judge(l), max(judge(l+1), judge(r))));
    }

    return 0;
}