#include <iostream>

using namespace std;

int main()
{
   int n;
   cin>>n;
   int w=0;

       int x=n%100;
       w+=(n-x)/100;
       n=x;



        x=n%20;
       w+=(n-x)/20;
      n=x;


        x=n%10;
       w+=(n-x)/10;
      n=x;


        x=n%5;
       w+=(n-x)/5;
     n=x;


        x=n%1;
       w+=(n-x)/1;
      n=x;

   cout<<w;
    return 0;
}