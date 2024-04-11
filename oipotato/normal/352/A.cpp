#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n,x=0,y=0;
    scanf("%d",&n);
    rep(i,n)
    {
        int tmp;scanf("%d",&tmp);
        if(tmp==5)x++;else y++;
    }
    if(!y)puts("-1");
    else if(x<9)puts("0");
    else
    {
        rep(i,x/9*9)putchar('5');
        rep(i,y)putchar('0');
        puts("");
    }
    return 0;
}