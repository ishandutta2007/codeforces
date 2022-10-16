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
    ll a,b;
    scanf("%lld %lld",&a,&b);
    ll tr=1;
    vector<int> res1,res2;
    while(true)
    {
        if((ll)tr*(tr+1)/2<=a)
        {
            res1.pb(tr);
        }
        else
            break;
        tr++;
    }
    int da=1;
    int skip=(ll)tr*(tr+1)/2-a;
    int start=tr+1;
    if((ll)(tr-1)*tr/2==a)
    {
        da=0;
        skip=0;
        start=tr;
    }
    else
    {
        res1.pb(tr);
    }
    //printf("%i %i\n",start,skip);
    int tr2=skip;
    if(skip!=0&&skip<=b)
    {
        res2.pb(skip);
    }
    int lim=1e6;
    for(int i=start;i<lim;i++)
    {
        if(tr2+i<=b)
        {
            res2.pb(i);
        }
        else
        {
            break;
        }
        tr2+=i;
    }
    printf("%i\n",res1.size()-da);
    for(auto p:res1)
    {
        if(p!=skip)
        printf("%i ",p);
    }
    printf("\n%i\n",res2.size());
    for(auto p:res2)
    {
        printf("%i ",p);
    }
    printf("\n");
    return 0;
}