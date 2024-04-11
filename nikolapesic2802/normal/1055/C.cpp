#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int main()
{
    int la,ra,ta;
    scanf("%i %i %i",&la,&ra,&ta);
    int lb,rb,tb;
    scanf("%i %i %i",&lb,&rb,&tb);
    int diff=gcd(ta,tb);
    int deltal=la-lb;
    int deltar=ra-rb;
    if((ll)deltal*deltar<=0)
    {
        int a=min(abs(la-ra+1),abs(lb-rb+1));
        printf("%i\n",a);
        return 0;
    }
    if(deltal<0)
    {
        deltal*=-1;
        deltar*=-1;
        //printf("%i %i\n",deltal,deltar);
        int mog=deltal/diff;
        deltal-=mog*diff;
        deltar-=mog*diff;
        int poz1=la+deltal;
        int poz2=ra+deltar;
        int r1=max(0,min(poz2,ra)-max(la,poz1)+1);
        poz1-=diff;
        poz2-=diff;
        r1=max(r1,min(poz2,ra)-max(la,poz1)+1);
        printf("%i\n",r1);
        return 0;
    }
    if(deltal>=0)
    {
        int mog=deltar/diff;
        deltal-=mog*diff;
        deltar-=mog*diff;
        int poz1=la-deltal;
        int poz2=ra-deltar;
        int r1=max(0,min(poz2,ra)-max(la,poz1)+1);
        poz1+=diff;
        poz2+=diff;
        r1=max(r1,min(poz2,ra)-max(la,poz1)+1);
        printf("%i\n",r1);
        return 0;
    }
    return 0;
}