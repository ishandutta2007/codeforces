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
        rep(i,n)
        {
            rep(j,i)putchar('(');
            putchar(')');
            rep(j,n-i)putchar('(');
            rep(j,n-1)putchar(')');
            puts("");
        }
    }
    return 0;
}