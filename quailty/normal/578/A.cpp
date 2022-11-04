#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(b>a)printf("-1\n");
    else
    {
        int k=(a/b)+1;
        if(k%2)k--;
        printf("%.12f\n",(a+b)/(k+0.0));
    }
    return 0;
}