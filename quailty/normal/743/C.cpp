#include<cstdio>
#include<cstdlib>
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
    if(n==1)printf("-1\n");
    else printf("%d %d %d\n",n,(n+1),n*(n+1));
    return 0;
}