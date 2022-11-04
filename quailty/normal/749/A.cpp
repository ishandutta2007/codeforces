#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",n/2);
    for(int i=0;i<n/2;i++)
        printf("%d ",2+(i==0 && n%2==1));
    return 0;
}