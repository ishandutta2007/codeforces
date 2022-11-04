#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const double PI=acos(-1.0);
const double eps=1e-9;
int main()
{
    int n,R,r;
    scanf("%d%d%d",&n,&R,&r);
    if(n==1)printf("%s",(R>=r ? "YES" : "NO"));
    else printf("%s",((R-r)*sin(PI/n)>r-eps ? "YES" : "NO"));
    return 0;
}