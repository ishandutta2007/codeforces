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
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        if((r-l+1)%2==0||l%2==0)puts(k>=(r-l+1)/2?"YES":"NO");
        else if(l==r&&l!=1)puts("YES");
        else puts(k>=(r-l+1)/2+1?"YES":"NO");
    }
    return 0;
}