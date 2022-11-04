#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,z;
    scanf("%d%d%d",&n,&m,&z);
    printf("%d",z/(n*m/__gcd(n,m)));
    return 0;
}