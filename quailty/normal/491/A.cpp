#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    int A,B;
    scanf("%d%d",&A,&B);
    for(int i=0;i<B;i++)
    {
        printf("%d ",A+B+1-i);
    }
    for(int i=0;i<=A;i++)
    {
        printf("%d ",i+1);
    }
    return 0;
}