#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db PI=acos(-1.0);
int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    printf("%.20f\n",n*sin(PI/(2*n))/sin(3*PI/(2*n))*r*r*sin(PI/n));
    return 0;
}