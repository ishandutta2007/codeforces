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
    int t=n,r=0;
    while(t>=10)t/=10,r++;
    t++;
    while(r>0)t*=10,r--;
    printf("%d\n",t-n);
    return 0;
}