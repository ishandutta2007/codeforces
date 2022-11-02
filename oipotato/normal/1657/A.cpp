#include<bits/stdc++.h>
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
        int x,y;scanf("%d%d",&x,&y);
        if(!x&&!y)puts("0");
        else
        {
            int now=x*x+y*y;
            int dis=(int)sqrt(now);
            if(dis*dis==now)puts("1");
            else puts("2");
        }
    }
    return 0;
}