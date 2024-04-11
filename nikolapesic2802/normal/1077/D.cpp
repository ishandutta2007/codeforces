#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
vector<pair<int,int> > kol;
vector<int> res;
bool test(int n,int k)
{
    res.clear();
    for(auto p:kol)
    {
        int br=p.first/n;
        while(res.size()<k&&br)
            res.pb(p.second),br--;
    }
    if(res.size()==k)
        return true;
    return false;
}
int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    map<int,int> mapa;
    int a;
    for(int i=0;i<n;i++)
        scanf("%i",&a),mapa[a]++;
    for(auto p:mapa)
        kol.pb({p.second,p.first});
    sort(kol.begin(),kol.end());
    reverse(kol.begin(),kol.end());
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(test(mid,k))
            l=mid;
        else
            r=mid-1;
    }
    assert(test(l,k));
    for(auto p:res)
        printf("%i ",p);
    return 0;
}