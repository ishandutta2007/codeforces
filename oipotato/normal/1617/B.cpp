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
        int n;
        scanf("%d",&n);
        if(n&1)
        {
            rep(i,100)if(i!=1&&__gcd(i,n-1-i)==1){printf("%d %d 1\n",i,n-1-i);break;}
        }
        else printf("%d %d 1\n",(n-1)/2,(n-1)/2+1);
    }
    return 0;
}