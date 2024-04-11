#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
void test()
{
    int d;
    scanf("%i",&d);
    if(d*d-4*d<0)
    {
        printf("N\n");
        return;
    }
    int dd=d*d-4*d;
    double sq=(double)sqrt(dd);
    double b1=(double)(sq+d)/2;
    double b2=(double)(d-sq)/2;
    double a1=(double)d-b1;
    double a2=(double)d-b2;
    if(a1>=0&&b1>=0)
    {
        printf("Y %.10f %.10f\n",a1,b1);
        return;
    }
    if(a2>=0&&b2>=0)
    {
        printf("Y %.10f %.10f\n",a2,b2);
        return;
    }
    printf("N\n");
}
int main()
{
    int t;
    scanf("%i",&t);
    while(t--)
        test();
    return 0;
}