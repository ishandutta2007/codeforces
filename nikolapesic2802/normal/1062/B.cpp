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
    int n;
    scanf("%i",&n);
    vector<int> factors;
    int minn=1;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            minn*=i;
            factors.pb(0);
            while(n%i==0)
            {
                factors.back()++;
                n/=i;
            }
        }
    }
    int maxx=0;
    bool test=false;
    int m=0;
    for(int i=0;i<factors.size();i++)
    {
        //printf("%i\n",factors[i]);
        int tr=0;
        int t=1;
        while(t<factors[i])
        {
            t*=2;
            tr++;
        }
        m=max(m,t);
        maxx=max(maxx,tr);
    }
    for(int i=0;i<factors.size();i++)
    {
        if(factors[i]!=m)
            test=true;
    }
    if(test)
        maxx++;
    printf("%i %i\n",minn,maxx);
    return 0;
}