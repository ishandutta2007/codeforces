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
    int n,k;
    scanf("%i %i",&n,&k);
    vector<int> xx(n),yy(n);
    for(int i=0;i<n;i++)
        scanf("%i",&xx[i]);
    for(int i=0;i<n;i++)
        scanf("%i",&yy[i]);
    int t=0,f=0;
    for(int i=0;i<n;i++)
    {
        int x=xx[i],y=yy[i];
        //printf("%i %i\n",t,f);
        if(t>k||f>k)
        {
            printf("NO\n");
            return 0;
        }
        if(x<y||x==y&&f>0)
        {
                y+=f;
                if((ll)x*k<y)
                {
                    f=y-x*k;
                    t=0;
                }
                else
                {
                    f=0;
                    t=0;
                }
        }
        else
        {
                x+=t;
                if((ll)y*k<x)
                {
                    t=x-y*k;
                    f=0;
                }
                else
                {
                    f=0;
                    t=0;
                }
        }
    }
    if(t>k||f>k)
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
    return 0;
}