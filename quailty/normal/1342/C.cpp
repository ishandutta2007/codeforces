#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,q;
        scanf("%d%d%d",&a,&b,&q);
        int p=a*b/__gcd(a,b);
        vector<int> can;
        for(int i=0;i<p;i++)
            if(i%a%b==i%b%a)
                can.push_back(i);
        for(int i=0;i<q;i++)
        {
            ll l,r,res=0;
            scanf("%lld%lld",&l,&r);
            for(auto &t:can)
                res+=(r+p-t)/p-(l-1+p-t)/p;
            printf("%lld%c",(r-l+1)-res, " \n"[i==q-1]);
        }
    }
    return 0;
}