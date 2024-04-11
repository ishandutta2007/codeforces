#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%s",(min(n,m)&1 ? "Akshat" : "Malvika"));
    return 0;
}