#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
int kk;
int flip(int i)
{
    return kk^i;
}
int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    vector<int> niz(n);
    kk=pow(2,k)-1;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
        //printf("%i\n",flip(niz[i]));
    }
    int tr=0;
    ll res=0;
    map<int,int> num;
    num[0]++;
    for(int i=0;i<n;i++)
    {
        if(num[(tr^niz[i])]>num[(tr^flip(niz[i]))])
            niz[i]=flip(niz[i]);
        res+=i+1-num[(tr^niz[i])];
        tr=(tr^niz[i]);
        num[tr]++;
    }
    printf("%lld\n",res);
    return 0;
}