#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define F first
#define S second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
 fast;
 string s;
 string a="hello";
  int i=0;
    
    cin >> s;
    
    for(auto c : s)
    {
        
     if(c==a[i] && i==4) { cout << "YES"; return 0;}
     if ( c==a[i] && i<4) i++;
 
    }
    
    cout << "NO";
    
}