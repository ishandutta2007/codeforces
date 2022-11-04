#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int p[4];
    for(int i=0;i<4;i++)
        scanf("%d",&p[i]);
    sort(p,p+4);
    for(int i=0;i<2;i++)
        if(p[i]+p[i+1]>p[i+2])
            return 0*printf("TRIANGLE");
    for(int i=0;i<2;i++)
        if(p[i]+p[i+1]==p[i+2])
            return 0*printf("SEGMENT");
    return 0*printf("IMPOSSIBLE");
}