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
    vector<int> poz(n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        poz[a]=i;
    }
    int tr=-1;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        //printf("%i %i\n",poz[a],tr);
        printf("%i ",max(0,poz[a]-tr));
        if(poz[a]>tr)
            tr=poz[a];
    }
    printf("\n");
    return 0;
}