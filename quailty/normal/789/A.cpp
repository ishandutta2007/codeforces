#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k,r=0;
    scanf("%d%d",&n,&k);
    for(int i=1,w;i<=n;i++)
    {
        scanf("%d",&w);
        r+=(w+k-1)/k;
    }
    return 0*printf("%d",(r+1)/2);
}