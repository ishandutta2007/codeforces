#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n; cin>>n;
   int * a=new int[n];
   for(int i=0;i<n;i++) cin>>a[i];
   sort(a,a+n);
   cout<<min(a[n-1]-a[1],a[n-2]-a[0]);
    return 0;
}