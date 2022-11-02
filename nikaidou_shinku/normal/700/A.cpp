#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
int main()
{
    int n,l,v1,v2,k;
    scanf("%d%d%d%d%d",&n,&l,&v1,&v2,&k);
    db tl=0,tr=1.0*l/v1;
    for(int _=0;_<100;_++)
    {
        db tm=(tl+tr)/2;
        db s=l-tm*v1;
        if((n+k-1)/k*(s/(v2-v1))+((n+k-1)/k-1)*(s/(v2+v1))>tm)tl=tm;
        else tr=tm;
    }
    return 0*printf("%.12f",(tl+tr)/2);
}