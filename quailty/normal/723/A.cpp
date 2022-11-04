#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int x[3];
    for(int i=0;i<3;i++)
        scanf("%d",&x[i]);
    sort(x,x+3);
    printf("%d\n",x[2]-x[0]);
    return 0;
}