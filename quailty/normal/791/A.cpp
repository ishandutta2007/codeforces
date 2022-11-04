#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=1;;i++)
    {
        a*=3,b*=2;
        if(a>b)return 0*printf("%d\n",i);
    }
    return 0;
}