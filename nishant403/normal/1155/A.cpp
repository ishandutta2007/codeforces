#include <bits/stdc++.h>
using namespace std;

int main()
{
 string s;
    int n;
   cin >> n; 
    cin >> s;
    
  int k =-1;  
     
     for(int i=0;i<n-1;i++)
 {
         if(s[i+1] < s[i] ) { k=i+1; break; }
         
 }
    
    if(k==-1) cout << "NO\n";
    else { cout << "YES\n"; cout <<  k << " " << k+1; } 
    
}