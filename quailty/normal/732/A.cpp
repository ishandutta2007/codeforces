#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int k,r;
    scanf("%d%d",&k,&r);
    for(int i=1;i<=10;i++)
        if(i*k%10==r || i*k%10==0)
            return 0*printf("%d",i);
}