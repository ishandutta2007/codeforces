#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,pair<int,int> >,null_type,less<pair<int,pair<int,int> > >,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()

int main()
{
    ordered_set s;
    int n,m;
    scanf("%i %i",&n,&m);
    vector<ll> sum(n);
    vector<int> x(n),y(n);
    vector<pair<int,pair<int,int> > > lol;
    for(int i=0;i<n;i++)
    {
        scanf("%i %i",&x[i],&y[i]);
        s.insert({y[i]-x[i],{x[i],y[i]}});
        lol.pb({y[i]-x[i],{x[i],y[i]}});
    }
    sort(lol.begin(),lol.end());
    vector<ll> prefx(n+1),prefy(n+1);
    for(int i=0;i<n;i++)
    {
        prefx[i+1]=(ll)prefx[i]+(ll)lol[i].second.first;
        prefy[i+1]=(ll)prefy[i]+(ll)lol[i].second.second;
        //printf("%lld %lld\n",prefx[i+1],prefy[i+1]);
    }
    for(int i=0;i<n;i++)
    {
        int k=s.order_of_key({y[i]-x[i],{x[i],y[i]}});
        //printf("Poz: %i\n",k);
        sum[i]=(ll)(k)*x[i];
        //printf("%lld\n",sum[i]);
        sum[i]+=(ll)(n-k-1)*y[i];
         //printf("%lld\n",sum[i]);
        sum[i]+=(ll)prefy[k];
        // printf("%lld\n",sum[i]);
        sum[i]+=(ll)prefx[n]-prefx[k+1];
       // printf("%i: %lld\n",i,sum[i]);
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        ll oduzmi;
        if(y[a]-x[a]>=y[b]-x[b])
        {
            oduzmi=x[a]+y[b];
        }
        else
        {
            oduzmi=x[b]+y[a];
        }
        sum[a]-=(ll)oduzmi;
        sum[b]-=(ll)oduzmi;
    }
    for(int i=0;i<n;i++)
    {
        printf("%lld ",sum[i]);
    }
    return 0;
}