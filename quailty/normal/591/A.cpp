#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int l,p,q;
    scanf("%d%d%d",&l,&p,&q);
    printf("%.10f\n",1.0*p*l/(p+q));
    return 0;
}