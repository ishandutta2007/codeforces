#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int tab[10005];

int main()
{
   int n; cin>>n;
   int * a=new int[n];
   for(int i=0;i<n;i++)
   {
        cin>>a[i];
   }
   sort(a,a+n);
   for(int i=0;i<n;i++) tab[a[i]]++;
   int x=a[n-1];
   for(int i=1;i<=x;i++)
   {
       if(x%i==0) tab[i]--;
   }
   int y;
   for(int i=10000;i>=1;i--)
   {
       if(tab[i]!=0) {y=i; break;}
   }
   cout<<x<<" "<<y;

    return 0;
}