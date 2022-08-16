#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
   fast;
    
   int a,b,k;
   cin >> a >> b >> k;
    
   string A,B;
   f(i,b) A+='1';
   f(i,a) A+='0';
   B = A;
    
   if(k == 0)
   {
       cout <<"Yes\n";
       cout << A << '\n';
       cout << B << '\n';
       
       return 0;
   }
    
   int mx = a + b - 2;
    
   if( ((b == 1 || a == 0) && k != 0) || k > mx)
   {
       cout <<"No";
       return 0;
   }
    
   if(k != 0)
   {
       swap(A.back(),A[k+1]);
       swap(B.back(),B[k+1]);
       swap(B[1],B[k+1]);
   }
    
   cout <<"Yes\n";
   cout << A << '\n';
   cout << B << '\n';
}