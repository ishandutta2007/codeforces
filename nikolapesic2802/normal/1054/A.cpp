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
    int x,y,z,t1,t2,t3;
    scanf("%i %i %i %i %i %i",&x,&y,&z,&t1,&t2,&t3);
    int time=3*t3;
    int dist=abs(x-z);
    time+=dist*t2;
    dist=abs(x-y);
    time+=dist*t2;
    int time2=dist*t1;
    if(time2<time)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    return 0;
}