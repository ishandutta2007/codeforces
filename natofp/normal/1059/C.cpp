#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
   int n; cin>>n;




       int akt=1;
       while(n)
       {
           if(n<=3)
           {
                if(n==1) cout<<akt;
                if(n==2) cout<<akt<<" "<<akt*2;
                if(n==3) cout<<akt<<" "<<akt<<" "<<akt*3;
                return 0;
           }
           else
           {
               for(int i=0;i<(n+1)/2;i++) cout<<akt<<" ";
                n/=2;
                akt*=2;
           }

       }


    return 0;
}