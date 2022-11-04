#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if(n<3)printf("%d",n+2);
    else printf("%d",n-2);
    return 0;
}