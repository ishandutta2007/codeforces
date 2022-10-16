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
    int n,m;
    scanf("%i %i",&n,&m);
    vector<vector<int> > graf(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        if(a>b){
            graf[a].pb(b);
            //printf("%i -> %i\n",a,b);
        }
        else{
            //printf("%i -> %i\n",b,a);
            graf[b].pb(a);
        }
    }
    int cord=0;
    vector<vector<pair<int,int> > > c(n);
    for(int i=0;i<n;i++)
    {
        //printf("WTF %i %i\n",i,cord);
        c[i].pb({i,cord});
        //printf("Usao za %i  %i\n",i,cord);
        cord++;
        for(auto p:graf[i])
        {
            c[i].pb({i,cord});
            c[p].pb({p,cord});
            cord++;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%i\n",c[i].size());
        for(auto p:c[i])
        {
            printf("%i %i\n",p.first+1,p.second+1);
        }
    }
    return 0;
}