#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int l,r,d;
        scanf("%d%d%d",&l,&r,&d);
        if(d<l)printf("%d\n",d);
        else
        {
            int res=r/d*d;
            while(res<=r)res+=d;
            printf("%d\n",res);
        }
    }
    return 0;
}