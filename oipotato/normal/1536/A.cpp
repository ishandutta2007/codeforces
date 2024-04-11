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
        int n;scanf("%d",&n);
        bool flag=0;
        rep(i,n){int x;scanf("%d",&x);if(x<0)flag=1;}
        if(flag)puts("NO");
        else
        {
            puts("YES");
            printf("101\n");
            rep(i,101)printf("%d%c",i-1," \n"[i==101]);
        }
    }
    return 0;
}