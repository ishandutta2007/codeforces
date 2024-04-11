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
    ll t;
    scanf("%i %lld",&n,&t);
    vector<int> po_velicini(n);
    vector<int> niz(n);
    ll sum=0;
    int minn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
        minn=min(minn,niz[i]);
        po_velicini[i]=niz[i];
        sum+=niz[i];
    }
    sort(po_velicini.begin(),po_velicini.end());
    reverse(po_velicini.begin(),po_velicini.end());
    int br=n;
    int tr=0;
    ll cnt=0;
    while(t>=minn){
        cnt+=(ll)(t/sum)*br;
        t=t%sum;
        for(int i=0;i<n;i++)
        {
            if(niz[i]<=t)
            {
                t-=niz[i];
                cnt++;
            }
        }
        while(po_velicini[tr]>t)
        {
            sum-=po_velicini[tr];
            tr++;
            br--;
        }
    }
    printf("%lld",cnt);
    return 0;
}