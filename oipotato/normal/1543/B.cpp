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
        int n,sum=0;scanf("%d",&n);
        rep(i,n){int x;scanf("%d",&x);(sum+=x)%=n;}
        printf("%lld\n",(LL)sum*(n-sum));
    }
    return 0;
}