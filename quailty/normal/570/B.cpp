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
    if(m<=n/2)printf("%d\n",min(n,m+1));
    else printf("%d\n",max(1,m-1));
    return 0;
}