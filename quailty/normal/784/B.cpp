#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt[16]={1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};
int main()
{
    int n;
    scanf("%d",&n);
    if(n==0)printf("1");
    else
    {
        int res=0;
        while(n)
        {
            res+=cnt[n%16];
            n/=16;
        }
        printf("%d",res);
    }
    return 0;
}