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
    int n,m;
    scanf("%i %i",&n,&m);
    vector<int> niz(n+1);
    niz[n]=1e9;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    sort(niz.begin(),niz.end());
    ordered_set blocked;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%i %i %i",&x,&y,&z);
        if(x==1)
        {
            blocked.insert({y,i});
        }
    }
    int minn=INT_MAX;
    for(int i=0;i<n+1;i++)
    {
        int tr=niz[i];
        int manje=blocked.order_of_key({tr,-1});
        //printf("Manje od %i: %i\n",tr,manje);
        int broj=blocked.size()-manje;
        minn=min(minn,i+broj);
    }
    printf("%i\n",minn);
    return 0;
}