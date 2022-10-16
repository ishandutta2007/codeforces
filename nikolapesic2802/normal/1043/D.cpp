#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
vector<vector<int> > graf;
int duz[100005];
int duzina(int tr)
{
    if(duz[tr]!=-1)
        return duz[tr];
    if(graf[tr].size()>0)
    {
        assert(graf[tr].size()==1);
        return duz[tr]=1+duzina(graf[tr][0]);
    }
    return duz[tr]=1;
}
int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    vector<int> sl(n+1);
    memset(duz,-1,sizeof(duz));
    vector<pair<int,int> > pos;
    for(int j=0;j<m;j++)
    {
        int prosli;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%i",&a);
            if(i!=0)
            {
                if(sl[prosli]==0)
                {
                    sl[prosli]=a;
                }
                else
                {
                    if(sl[prosli]!=a)
                    {
                        sl[prosli]=-1;
                    }
                }
            }
            if(i==n-1)
            {
                sl[a]=-1;
            }
            prosli=a;
        }
    }
    ll sum=0;
    graf.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        if(sl[i]>0)
        graf[i].pb(sl[i]);
        //if(sl[i]>0)
        //printf("%i %i\n",i,sl[i]);
    }
    for(int i=1;i<=n;i++)
    {
        //printf("%i: %i\n",i,duzina(i));
        sum+=(ll)duzina(i);
    }
    printf("%lld\n",sum);
    return 0;
}