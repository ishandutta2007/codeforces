#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
 int q;
 cin >> q;
  while(q--)
  {
 unsigned int a,i,x=1;
 
 cin >> a ;
 if( (a&(a+1)) > 0) 
 {
     while(x<=a) x<<=1;
     cout << x-1 << "\n";
 }
 else
 {
     for(i=2;i*i<=a;i++)
     if(a%i==0) 
      {
       x=a/i; 
       break;
      }
     
     cout << x << "\n";
 }
 
}

}