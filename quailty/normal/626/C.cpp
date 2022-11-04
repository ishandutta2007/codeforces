#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int l=0,r=1000000000;
    while(l<r)
    {
        int t=(l+r)>>1;
        int tn=t/2-t/6;
        int tm=t/3-t/6;
        int tx=t/6;
        if(tx>=max(n-tn,0)+max(m-tm,0))r=t;
        else l=t+1;
    }
    printf("%d\n",l);
    return 0;
}