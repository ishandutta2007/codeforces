#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,b,p;
    scanf("%d%d%d",&n,&b,&p);
    printf("%d %d\n",(n-1)*(2*b+1),n*p);
    return 0;
}