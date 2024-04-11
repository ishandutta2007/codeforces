#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long int a,b,c,d;
   cin>>a>>b>>c>>d;
   long long int x=(c+d)/b+bool((c+d)%b);
   if(x*b>a) {cout<<-1; return 0;}
   cout<<x;

    return 0;
}