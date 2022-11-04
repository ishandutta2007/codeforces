#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",(n/k+1)*k);
    return 0;
}