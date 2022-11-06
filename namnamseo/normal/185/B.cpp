#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int sum;
    int a,b,c;
    cin>>sum>>a>>b>>c;
    if(a+b+c==0){
        printf("0 0 0");
        return 0;
    }
    double div=sum*1.0/(a+b+c);
    double p=div*a,q=div*b,r=div*c;
    printf("%.15f %.15f %.15f\n",p,q,r);
    return 0;
}