#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int x[2],y[2];
    for(int i=0;i<2;i++)
        scanf("%d%d",&x[i],&y[i]);
    printf("%d",max(abs(x[1]-x[0]),abs(y[1]-y[0])));
    return 0;
}