#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a=0,b=0,n;
    for(int i=0;i<3;i++)
    {
        int t;
        scanf("%d",&t);
        a+=t;
    }
    for(int i=0;i<3;i++)
    {
        int t;
        scanf("%d",&t);
        b+=t;
    }
    scanf("%d",&n);
    printf("%s",((a+4)/5+(b+9)/10<=n ? "YES" : "NO"));
    return 0;
}