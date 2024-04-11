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
    int cnt=0;
    while(2*n>m && m>0 && n>1)
    {
        cnt++;
        n-=2;
        m--;
    }
    if(2*n<=m)cnt+=n;
    printf("%d",cnt);
    return 0;
}