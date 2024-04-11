#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
       int n;
       cin>>n;
       long double l=n/2.;
       long double r=n;
       for(int i=1;i<=1000;i++)
       {
            long double mid=(l+r)/2.;
            if ((n-mid)*mid<n)r=mid; else l=mid;
       } 
       long double  a=l; long double b=n-l;
       if (abs(a*b-n)<=0.00000001)
       {
            printf("Y %.10Lf %.10Lf\n",a,b);
       }
       else puts("N");
    }

}