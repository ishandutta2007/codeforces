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
    multiset<int> lol;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        lol.insert(a);
    }
    multiset<int>::iterator it=lol.end();
    it--;
    printf("%i ",(*it)-*lol.begin());
    if((*it)-*lol.begin()==0)
    {
        printf("%lld\n",(ll)n*(n-1)/2);
    }
    else
    {
        printf("%lld\n",(ll)lol.count((*it))*lol.count(*lol.begin()));
    }
    return 0;
}