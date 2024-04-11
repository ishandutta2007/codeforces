#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int t[95];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    t[n+1]=90;
    for(int i=0;i<=n;i++)
        if(t[i+1]>t[i]+15)
            return 0*printf("%d",t[i]+15);
    return 0*printf("90");
}