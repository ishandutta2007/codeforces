#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()

int main()
{
    ordered_set o;
    for(int i=0;i<3;i++)
    {
        int a;
        scanf("%i",&a);
        o.insert({a,i});
    }
    printf("%i\n",max(0,(*o.find_by_order(2)).first-(*o.find_by_order(1)).first-(*o.find_by_order(0)).first+1));
    return 0;
}