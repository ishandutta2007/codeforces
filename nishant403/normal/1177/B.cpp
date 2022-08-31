#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main()
{
int k;
cin >> k;
    
int digit = 0;   
int last = 0; 
    
 while(1)
 {
    
     if(k < ++digit*9*pow(10,digit-1) ) break;
     
     k-= (digit*9*pow(10,digit-1));
     last=(last*10 + 9);
 }     
    cout << ((last + (k+digit-1)/digit) /(int)pow(10,(digit-(k%digit))%digit) )% 10;
}