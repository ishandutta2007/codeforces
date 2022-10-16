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
    int tr=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        if(a>tr)
        {
            printf("%i\n",i+1);
            return 0;
        }
        if(a==tr)
        {
            tr++;
        }
    }
    printf("-1\n");
    return 0;
}