#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int m[5],w[5],h[2];
    for(int i=0;i<5;i++)
        scanf("%d",&m[i]);
    for(int i=0;i<5;i++)
        scanf("%d",&w[i]);
    for(int i=0;i<2;i++)
        scanf("%d",&h[i]);
    int res=0;
    for(int i=0;i<5;i++)
        res+=max(150*(i+1),(500-2*m[i])*(i+1)-50*w[i]);
    res+=100*h[0]-50*h[1];
    printf("%d\n",res);
    return 0;
}