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
    int n,s;
    scanf("%i %i",&n,&s);
    vector<int> niz(n);
    vector<int> niz2(n);
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%i",&niz2[i]);
    }
    s--;
    if(s==0)
    {
        printf("YES\n");
        return 0;
    }
    if(niz[0]==0)
    {
        printf("NO\n");
        return 0;
    }
    if(niz[s]==1)
    {
        printf("YES\n");
        return 0;
    }
    if(niz2[s]==0)
    {
        printf("NO\n");
        return 0;
    }
    for(int i=s+1;i<n;i++)
    {
        if(niz[i]==1&&niz2[i]==1)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}