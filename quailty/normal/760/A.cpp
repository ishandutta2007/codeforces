#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int m,d,r=1;
    scanf("%d%d",&m,&d);
    m--,d--;
    for(int i=1;i<day[m];i++)
        if((++d)==7)r++,d=0;
    return 0*printf("%d",r);
}