#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define F first
#define S second
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
 fast;   
 int i,j,n,k;
   string s; 
  cin >> n;
   while(n--)
   {
       cin >> s >> i >> j;
       if(i>=2400 && (j-i > 0) ) {cout << "YES"; return 0; }
   }
    
    cout << "NO";
}