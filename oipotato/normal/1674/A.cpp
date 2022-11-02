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
        printf("%d %d\n",y%x==0?1:0,y%x==0?y/x:0);
    }
    return 0;
}