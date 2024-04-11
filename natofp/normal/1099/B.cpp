#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{

   int n; cin>>n;
   int i=sqrt(n);
   if(i*i==n) cout<<2*i;
    else if(i*(i+1)>=n) cout<<2*i+1;
    else cout<<2*i+2;
    return 0;
}