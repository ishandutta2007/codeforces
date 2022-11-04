#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int A,B,res=1;
    scanf("%d%d",&A,&B);
    for(int i=1;i<=A && i<=B;i++)
        res*=i;
    return 0*printf("%d\n",res);
}