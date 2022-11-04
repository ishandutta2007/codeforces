#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int ty,hh,mm;
    scanf("%d%d:%d",&ty,&hh,&mm);
    int now=2,rh=0,rm=0;
    for(int th=(ty==12 ? 1 : 0);th<=(ty==12 ? 12 : 23);th++)
    {
        int tmp=(th%10!=hh%10)+(th/10!=hh/10);
        if(now>=tmp)now=tmp,rh=th;
    }
    now=2;
    for(int tm=0;tm<=59;tm++)
    {
        int tmp=(tm%10!=mm%10)+(tm/10!=mm/10);
        if(now>=tmp)now=tmp,rm=tm;
    }
    printf("%02d:%02d\n",rh,rm);
    return 0;
}