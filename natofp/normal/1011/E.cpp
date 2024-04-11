#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{

  while(b)
  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main()
{
   int n,k;
   cin>>n>>k;
   int * a;
   a=new int[n];
   for(int i=0;i<n;i++) {cin>>a[i]; a[i]%=k;}
   int xd;
   if(n==1) xd=a[0];
   else
   {
        xd=gcd(a[0],a[1]);
        for(int i=2;i<n;i++)
            {
                xd=gcd(xd,a[i]);
            }
   }
   if(xd==0) {cout<<"1"<<endl; cout<<"0"; return 0;}
   xd=gcd(xd,k);

   {
       int wynik=k/xd;
       if(k%xd!=0) wynik++; cout<<wynik<<endl;
   for(int i=0;i<k;i+=xd)
    cout<<i<<" ";
   }



    return 0;
}