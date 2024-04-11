#include <cstdio>
#include <iostream>
#include <vector>
#define i64 long long
#define pb push_back
using namespace std;
const i64 mod = 1000000007;
i64 n,m,k;

int main()
{

    
    cin >> n >> m >> k;
    
    //if (k > n) { cout << "0" << endl; return 0; }
    
    if (m == 1) { cout << "1" << endl; return 0; }
    
    if (k == 1 || k > n) 
    { 
    i64 res = 1; for (int i=1;i<=n;i++) res = (res*m)%mod; 
    cout << res << endl; return 0;  
    }
    
    if (k == n)
    {
          i64 res = 1;
          for (int i=1;i<=(n+1)/2;i++)
           res = (res*m) % mod;
          cout << res << endl;
          return 0;
    }
    
    if (k % 2 == 0) { cout << m << endl; return 0; }
    
    cout << (m*m) % mod << endl;
    
    return 0;
}