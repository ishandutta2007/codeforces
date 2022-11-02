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
        if(x==1)puts(y==1?"YES":"NO");
        else if(x<=3)puts(y<=3?"YES":"NO");
        else puts("YES");
    }
    return 0;
}