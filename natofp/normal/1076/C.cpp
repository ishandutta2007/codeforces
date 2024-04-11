#include <iostream>
#include <bits/stdc++.h>


using namespace std;



int main()
{

   int t; cin>>t;
   while(t--)
   {
       double d; cin>>d;
       if(d>(d/2)*(d/2)) {cout<<"N"<<endl; continue;}
       double a,b;
       a=0;
       b=d;
       for(int i=0;i<120;i++)
       {
           double mid=(a+b)/2;
           if(mid*(d-mid)>=d)
           {
               b=mid;
           }
           else a=mid;
       }
       double k=(a+b)/2;
       cout<<"Y"<<" "<<setprecision(10)<<k<<" "<<d-k<<endl;
   }

    return 0;
}