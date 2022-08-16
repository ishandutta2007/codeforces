#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

int main()
{
 int n,a,b;
    
    cin >> n >> b >> a;
    
    int a1=a;
    int b1=b;
    
 int A[n];
    f(i,n) cin >> A[i];
    
 f(i,n)
 {
     if(A[i]==0)
     {
      if(a > 0 ) a--;   
      else b--;   
     }
     
     else
     { 
         if(b>0 && a!=a1) b--,a++;
         else a--;
     }
     
      if(a==0 && b==0){ cout << i+1; return 0; } 
 }
 cout << n;
}