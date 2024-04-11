#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    printf("%d",((a-1+b)%n+n)%n+1);
    return 0;
}