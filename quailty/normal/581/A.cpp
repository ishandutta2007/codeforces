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
    if(a>b)swap(a,b);
    printf("%d %d\n",a,(b-a)/2);
    return 0;
}