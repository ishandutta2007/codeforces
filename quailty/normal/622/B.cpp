#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int hh,mm;
    scanf("%d:%d",&hh,&mm);
    int a;
    scanf("%d",&a);
    mm+=a;
    while(mm>=60)
    {
        mm-=60;
        hh++;
    }
    hh%=24;
    printf("%02d:%02d",hh,mm);
    return 0;
}