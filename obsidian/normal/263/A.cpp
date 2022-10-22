#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
int AB(int x){if(x<0)return -x;return x;}
int x;
int main()
{
    for(int i=1;i<=5;i++)
    for(int j=1;j<=5;j++)
    {
        scanf("%d",&x);
        if(x==1)
        {
            printf("%d\n",AB(i-3)+AB(j-3));
        }
    }
}