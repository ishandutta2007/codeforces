#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
const int N=1e5+5;
int main()
{
    int n;
    scanf("%i",&n);
    ll score=0;
    for(int i=4;i<=n;i++)
    {
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                //printf("Usao za %i %i\n",i,j);
                if(i/j==j)
                {
                    //printf("Dodajem %i\n",i);
                    score+=j;
                }
                else
                {
                    score+=j;
                    score+=i/j;
                }
            }
        }
    }
    printf("%lld\n",(ll)score*4);
    return 0;
}