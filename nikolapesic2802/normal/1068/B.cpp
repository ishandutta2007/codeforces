#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()

int main()
{
    ll b;
    scanf("%lld",&b);
    ll d=b;
    vector<int> f;
    for(int i=2;i<=(ll)sqrt(b);i++)
    {
        if(d%i==0)
        {
            f.pb(0);
            while(d%i==0)
            {
                f[f.size()-1]++;
                d/=i;
            }
        }
    }
    if(d>1)
    {
        f.pb(1);
    }
    ll p=1;
    for(auto pd:f)
    {
        p*=(pd+1);
    }
    printf("%lld\n",p);
    return 0;
}