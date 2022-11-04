#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
int main()
{
    int n;
    scanf("%d",&n);
    printf("%I64d\n",1LL*3*n*(n+1)+1);
    return 0;
}