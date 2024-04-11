#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
void work(LL&x)
{
    LL y=0;
    for(;x;x/=10)if(x%10)y=y*10+x%10;
    x=y;
}
int main()
{
    LL a,b,c;scanf("%lld%lld",&a,&b);
    c=a+b;
    rep(i,2)work(a),work(b),work(c);
    puts(a+b==c?"YES":"NO");
    return 0;
}