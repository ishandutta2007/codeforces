#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   int ile=(n+1)/2;
   int k=ile%m;
   k=m-k;
   k%=m;
   if(k>n/2) {cout<<-1; return 0;}
   else cout<<ile+k;
    return 0;
}