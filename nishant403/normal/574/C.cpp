#include <bits/stdc++.h>
using namespace std;
#define int long long 

int gcd(int a,int b)
{
 if(b==0) return a;
    return gcd(b,a%b);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        int n;
    cin >> n;
    
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    
   for(int i=0;i<n-1;i++)
   {
     int x = a[i];  
     int y = a[i+1];  
       
     int g = gcd(x,y);
       
      x/=g;
       y/=g;
      
     while(x%2==0) x/=2;
     while(y%2==0) y/=2;
     while(x%3==0) x/=3;
     while(y%3==0) y/=3;
         
    if(x!=1 || y!=1) { cout << "No"; return 0; } 
   }
cout << "Yes";

}