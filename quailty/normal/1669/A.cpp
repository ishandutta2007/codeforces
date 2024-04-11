#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int r,d;
        scanf("%d",&r);
        if(r<=1399)d=4;
        else if(r<=1599)d=3;
        else if(r<=1899)d=2;
        else d=1;
        printf("Division %d\n",d);
    }
    return 0;
}