#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int res[4];
int main()
{
    ll x;
    scanf("%I64d",&x);
    x=-x;
    x=(x%360+360)%360;
    for(int i=0;i<=3;i++)
    {
        res[i]=x;
        x=(x+90)%360;
    }
    for(int i=0;i<4;i++)
        res[i]=min(res[i],360-res[i]);
    int loc=0;
    for(int i=0;i<4;i++)
        if(res[loc]>res[i])loc=i;
    printf("%d\n",loc);
    return 0;
}