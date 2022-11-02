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
        int n,k;scanf("%d%d",&n,&k);
        rep(i,n)putchar((i%3)+'a');
        puts("");
    }
    return 0;
}