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
    long long t;
    scanf("%*d%I64d",&t);
    int res=1;
    while(t%2==0)t/=2,res++;
    printf("%d\n",res);
    return 0;
}