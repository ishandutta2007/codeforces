#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main()
{
int k;
cin >> k;
    
int digit = 0;
int sum = 0;    
 
 while(1)
 {
     digit++;
     sum+=(digit*9*pow(10,digit-1));
     
     if(k < sum ) break;
 }
    
 for(int i=1;i<digit;i++) k-=(i*9*pow(10,i-1));    
 
 int last = 0;   
    
    for(int i=1;i<digit;i++) {last = last*10+9; }   
    
    last+=(k/digit);
    
    if(k%digit==0) { cout << last%10; }
    else {
        last++;
      //now print k%digit th digit of number last 
        cout << (( last/(int)pow(10,digit - (k%digit) ) )%10 ) ;
    }
}