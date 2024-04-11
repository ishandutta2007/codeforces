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
    ll n,m,k,l;
    scanf("%lld %lld %lld %lld",&n,&m,&k,&l);
    ll possible=n-k;
    ll minn=k+l;
    ll lol=minn/m;
    if(minn%m!=0)
        lol++;
    if(lol*m>n)
        printf("-1\n");
    else
        printf("%lld\n",lol);
    return 0;
}