#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int c[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int res=0;
    for(int i=a;i<=b;i++)
    {
        int t=i;
        while(t)
        {
            res+=c[t%10];
            t/=10;
        }
    }
    printf("%d\n",res);
    return 0;
}