#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int c[10]={2,7,2,3,3,4,2,5,1,2};
int main()
{
    int n;
    scanf("%d",&n);
    int a=n%10,b=n/10;
    printf("%d\n",c[a]*c[b]);
    return 0;
}