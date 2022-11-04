#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    printf("%d %d %c",(k-1)/(2*m)+1,(k-1)%(2*m)/2+1,"RL"[k&1]);
    return 0;
}