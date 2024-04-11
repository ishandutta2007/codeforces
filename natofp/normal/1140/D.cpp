#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int suma=0;
long long int res=0;
int roz=0;

int main()
{
   long long int n; cin>>n;
   long long int res=0;
   for(long long int i=3;i<=n;i++)
   {
       res+=(i)*(i-1);
   }
   cout<<res;

    return 0;
}