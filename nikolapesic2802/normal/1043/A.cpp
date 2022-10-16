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
    int maxx=0,sum=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        maxx=max(maxx,a);
        sum+=a;
    }
    for(int k=1;k<1000;k++)
    {
        if(k>=maxx&&k*n-sum>sum)
        {
            printf("%i\n",k);
            return 0;
        }
    }
    return 0;
}