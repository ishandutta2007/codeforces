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
    int n,m,k;
    scanf("%i %i %i",&n,&m,&k);
    int sum=0;
    for(int i=0;i<k;i++)
    {
        int x1=max((n-4*i),0);
        int x2=max(0,(m-4*i));
        int x3=max((n-(4*i)-2),0);
        int x4=max(0,(m-(4*i)-2));
        //printf("%i %i   %i %i\n",x1,x2,x3,x4);
        sum+=x1*x2-x3*x4;
    }
    printf("%i\n",sum);
    return 0;
}