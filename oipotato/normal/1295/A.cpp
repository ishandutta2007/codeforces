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
        if(n&1)
        {
            putchar('7');
            rep(i,(n-3)/2)putchar('1');
            puts("");
        }
        else
        {
            rep(i,n/2)putchar('1');
            puts("");
        }
    }
    return 0;
}