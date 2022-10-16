#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
   int n; cin>>n;
   long long int * a;
   a=new long long int[n];
   long long int ile=0;
   for(int i=0;i<n;i++) cin>>a[i];
   cout<<n+1<<endl;
   for(int i=n-1;i>=0;i--)
   {
       long long int dodaj;
       dodaj=n+i-(a[i]+ile)%n;
       if(dodaj>=n) dodaj%=n;
       ile+=dodaj;
       cout<<"1"<<" "<<i+1<<" "<<dodaj<<endl;
   }
   cout<<"2"<<" "<<n<<" "<<n<<endl;
    return 0;
}