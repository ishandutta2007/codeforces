#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
bool isleap(int x)
{
    return x%400==0 || (x%4==0 && x%100!=0);
}
int main()
{
    int y,z,ost=0;
    scanf("%d",&y);
    z=y;
    do
    {
        ost=(ost+365+isleap(++z))%7;
    }while(ost || isleap(y)!=isleap(z));
    return 0*printf("%d",z);
}