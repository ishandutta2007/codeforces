#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int nax=303;
vector<int> a[nax];

int main()
{
   int n; cin>>n;
   for(int i=0;i<n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(i%2==0)
           {
               a[j].push_back(i*n+j);
           }
           else
           {
               a[n-j+1].push_back(i*n+j);
           }
       }
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=0;j<n;j++) cout<<a[i][j]<<" ";
       cout<<endl;
   }
    return 0;
}