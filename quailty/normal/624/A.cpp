#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int d,L,v[2];
    scanf("%d%d%d%d",&d,&L,&v[0],&v[1]);
    printf("%.10f\n",(L-d+0.0)/(v[0]+v[1]));
    return 0;
}