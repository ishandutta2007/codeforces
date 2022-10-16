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
    int n,m,l;
    scanf("%i %i %i",&n,&m,&l);
    vector<ll> a(n+2);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>l&&a[i-1]<=l)
        {
            cnt++;
        }
    }
    for(int i=0;i<m;i++)
    {
        int t;
        scanf("%i",&t);
        if(t==0)
        {
            printf("%i\n",cnt);
        }
        else
        {
            int p,d;
            scanf("%i %i",&p,&d);
            if(a[p]<=l&&a[p]+d>l)
            {
                if(a[p-1]>l&&a[p+1]>l)
                {
                    cnt--;
                }
                if(a[p-1]<=l&&a[p+1]<=l)
                {
                    cnt++;
                }
            }
            a[p]+=d;
        }
    }
    return 0;
}