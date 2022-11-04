#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int num[105];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    int d=num[1]-num[0];
    bool f=1;
    for(int i=1;i<n && f;i++)
        if(num[i-1]+d!=num[i])
            f=0;
    if(!f) d=0;
    printf("%d\n",num[n-1]+d);
    return 0;
}