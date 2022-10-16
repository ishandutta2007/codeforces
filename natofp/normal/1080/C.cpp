#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int t; cin>>t;
   while(t--)
   {
       long long int n,m;
       cin>>n>>m;
       long long int x1,x2,x3,x4,y1,y2,y3,y4;
       cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
       long long int x5 = max(x1, x3);
       long long int y5 = max(y1, y3);
       long long int x6 = min(x2, x4);
       long long int y6 = min(y2, y4);
       long long int biale=n*m/2;
       if(n%2==1 && m%2==1) biale++;
       if((x2-x1)%2==1 || (y2-y1)%2==1)
       {
           biale+=(x2-x1+1)*(y2-y1+1)/2;
       }
       else
       {
           if((x1+y1)%2==1) biale++;
           biale+=(x2-x1+1)*(y2-y1+1)/2;
       }
       
       if((x4-x3)%2==1 || (y4-y3)%2==1)
       {
           biale-=(x4-x3+1)*(y4-y3+1)/2;
       }
       else
       {
           biale-=(x4-x3+1)*(y4-y3+1)/2;
           if((x3+y3)%2==0) biale--;
       }
      
       if(x5<=x6 && y5<=y6)
       {
           if((x6-x5)%2==1 || (y6-y5)%2==1)
       {
           biale-=(x6-x5+1)*(y6-y5+1)/2;
       }
       else
       {
           biale-=(x6-x5+1)*(y6-y5+1)/2;
           if((x5+y5)%2==1) biale--;
       }
       }
        cout<<biale<<" "<<n*m-biale<<endl;






   }
    return 0;
}