#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#define PI 3.14159265

int main()
{
    int  n,r;
    scanf("%d %d",&n,&r);
    printf("%.7Lf",(r*(long double)sin((2*PI)/n))/((long double)(2*cos(PI/n)) -sin((2*PI)/n)));
}