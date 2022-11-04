#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int xp,yp,xv,yv;
    scanf("%d%d%d%d",&xp,&yp,&xv,&yv);
    if(xp+yp>xv+yv)
    {
        printf("Vasiliy\n");
    }
    else
    {
        int t1=(yp-xp>yv-xv ? yp : xp);
        int t2=(yp-xp>yv-xv ? yv : xv);
        if(t1>t2)
        {
            if(t1<=max(xv,yv)-(xp+yp-t1))
            {
                printf("Polycarp\n");
            }
            else printf("Vasiliy\n");
        }
        else printf("Polycarp\n");
    }
    return 0;
}