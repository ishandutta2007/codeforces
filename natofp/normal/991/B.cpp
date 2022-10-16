#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int * a;
   a=new int[n];
   for(int i=0;i<n;i++)
     cin>>a[i];
    sort(a,a+n);
    double suma=0;
    for(int i=0;i<n;i++)
    {
        suma+=a[i];
    }
    int j=0;
    while(suma/n<4.5)
    {
        suma+=(5-a[j]);
        j++;
    }
    cout<<j;

    return 0;
}