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
    int tr=1;
    int cnt=0;
    int maxx=0;
    vector<int> niz(n+2);
    niz[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&niz[i]);
    }
    niz[n+1]=1001;
    for(int i=1;i<=n+1;i++)
    {
        //printf("%i %i\n",niz[i],niz[i-1]);
        if(niz[i]==niz[i-1]+1)
        {
            cnt++;
            maxx=max(maxx,cnt-1);
        }
        else
        {
            cnt=0;
        }
    }
    printf("%i\n",maxx);
    return 0;
}