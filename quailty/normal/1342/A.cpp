#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x,y,a,b;
        scanf("%d%d%d%d",&x,&y,&a,&b);
        ll res1=1LL*a*(x+y);
        ll res2=1LL*a*(x+y-2*min(x,y))+1LL*b*min(x,y);
        printf("%lld\n",min(res1,res2));
    }
    return 0;
}